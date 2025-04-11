#include "ProjectiveTextures.h"
#include <string>

/* CONSTRUCTOR */
CProjectiveTextures::CProjectiveTextures(irr::IrrlichtDevice* dev, irr::scene::ISceneNode* parent, irr::scene::ISceneManager* mgr, irr::s32 id,
	const irr::core::vector3df& position, const irr::core::vector3df& lookat)
	: irr::scene::ISceneNode(parent, mgr, id, position)
{
	pDevice	   = dev;
	pVideo     = pDevice->getVideoDriver();
	pScene     = pDevice->getSceneManager();
	pGUI       = pDevice->getGUIEnvironment();
	pGPU       = pVideo->getGPUProgrammingServices();
	pCollision = pScene->getSceneCollisionManager();
	pLog       = pDevice->getLogger();

	// set default projection
	Fovy = irr::core::PI / 2.5f;	// Field of view, in radians.

	Target = lookat;

	recalculateProjectionMatrix();
	recalculateViewArea();

	std::string projector_vert =
	"!!ARBvp1.0 \n"
	"# cgc version 2.1.0016, build date Nov 20 2008 \n"
	"# command line args: -oglsl -bestprecision -O3 -profile arbvp1 \n"
	"# source file: projector.vert \n"
	"#vendor NVIDIA Corporation \n"
	"#version 2.1.0.16 \n"
	"#profile arbvp1 \n"
	"#program main \n"
	"#semantic gl_ModelViewProjectionMatrixTranspose : state.matrix.mvp \n"
	"#semantic TexGenMat \n"
	"#var float4 gl_TexCoord[0] : $vout.TEX0 : TEX0 : -1 : 1 \n"
	"#var float4 gl_TexCoord[1] :  :  : -1 : 0 \n"
	"#var float4 gl_TexCoord[2] :  :  : -1 : 0 \n"
	"#var float4 gl_TexCoord[3] :  :  : -1 : 0 \n"
	"#var float4 gl_TexCoord[4] :  :  : -1 : 0 \n"
	"#var float4 gl_TexCoord[5] :  :  : -1 : 0 \n"
	"#var float4 gl_TexCoord[6] :  :  : -1 : 0 \n"
	"#var float4 gl_TexCoord[7] :  :  : -1 : 0 \n"
	"#var float4 gl_Vertex : $vin.POSITION : POSITION : -1 : 1 \n"
	"#var float4 gl_Position : $vout.POSITION : HPOS : -1 : 1 \n"
	"#var float4x4 gl_ModelViewProjectionMatrixTranspose : state.matrix.mvp : c[1], 4 : -1 : 1 \n"
	"#var float4x4 TexGenMat :  : c[5], 4 : -1 : 1 \n"
	"PARAM c[9] = { program.local[0], \n"
	"  state.matrix.mvp, \n"
	"  program.local[5..8] }; \n"
	"TEMP R0; \n"
	"MUL R0, vertex.position.y, c[6]; \n"
	"MAD R0, vertex.position.x, c[5], R0; \n"
	"MAD R0, vertex.position.z, c[7], R0; \n"
	"MAD result.texcoord[0], vertex.position.w, c[8], R0; \n"
	"DP4 result.position.w, vertex.position, c[4]; \n"
	"DP4 result.position.z, vertex.position, c[3]; \n"
	"DP4 result.position.y, vertex.position, c[2]; \n"
	"DP4 result.position.x, vertex.position, c[1]; \n"
	"END \n"
	"# 8 instructions, 1 R-regs \n"
	;


	std::string projector_frag =
	"!!ARBfp1.0 \n"
	"OPTION ARB_precision_hint_nicest; \n"
	"# cgc version 2.1.0016, build date Nov 20 2008 \n"
	"# command line args: -oglsl -bestprecision -O3 -profile arbfp1 \n"
	"# source file: projector.frag \n"
	"#vendor NVIDIA Corporation \n"
	"#version 2.1.0.16 \n"
	"#profile arbfp1 \n"
	"#program main \n"
	"#semantic projMap \n"
	"#var float4 gl_TexCoord[0] : $vin.TEX0 : TEX0 : -1 : 1 \n"
	"#var float4 gl_TexCoord[1] :  :  : -1 : 0 \n"
	"#var float4 gl_TexCoord[2] :  :  : -1 : 0 \n"
	"#var float4 gl_TexCoord[3] :  :  : -1 : 0 \n"
	"#var float4 gl_TexCoord[4] :  :  : -1 : 0 \n"
	"#var float4 gl_TexCoord[5] :  :  : -1 : 0 \n"
	"#var float4 gl_TexCoord[6] :  :  : -1 : 0 \n"
	"#var float4 gl_TexCoord[7] :  :  : -1 : 0 \n"
	"#var float4 gl_FragColor : $vout.COLOR : COL : -1 : 1 \n"
	"#var sampler2D projMap :  : texunit 0 : -1 : 1 \n"
	"#const c[0] = 0 \n"
	"PARAM c[1] = { { 0 } }; \n"
	"TEMP R0; \n"
	"TXP R0, fragment.texcoord[0], texture[0], 2D; \n"
	"CMP result.color, -fragment.texcoord[0].w, R0, c[0].x; \n"
	"END \n"
	"# 2 instructions, 1 R-regs \n"
	;

	// Load the shaders.
	projTex = pGPU->addShaderMaterial(projector_vert.c_str(),
									  projector_frag.c_str(),
									  this,irr::video::EMT_TRANSPARENT_ADD_COLOR,0);
}

/* DESTRUCTOR */
CProjectiveTextures::~CProjectiveTextures()
{
	// Remove the texture used.
	pVideo->removeTexture(texture);
}

//! sets the look at target of the projector
void CProjectiveTextures::setTarget(const irr::core::vector3df& pos)
{
	Target = pos;
	const irr::core::vector3df toTarget = Target - getAbsolutePosition();
}

//! Gets the current look at target of the projector
const irr::core::vector3df& CProjectiveTextures::getTarget() const
{
	return Target;
}

void CProjectiveTextures::setFOV(irr::f32 f)
{
	Fovy = f;
	recalculateProjectionMatrix();
}

irr::f32 CProjectiveTextures::getFOV()
{
	return Fovy;
}

//! returns the axis aligned bounding box of this node
const irr::core::aabbox3d<irr::f32>& CProjectiveTextures::getBoundingBox() const
{
	return ViewArea.getBoundingBox();
}

/* UPDATE */
void CProjectiveTextures::render()
{
	irr::core::vector3df pos = getAbsolutePosition();
	irr::core::vector3df tgtv = Target - pos;
	tgtv.normalize();

	// if upvector and vector to the target are the same, we have a
	// problem. so solve this problem:
	irr::core::vector3df up(0.0f,0.0f,1.0f);

	ViewArea.getTransform(irr::video::ETS_VIEW).buildCameraLookAtMatrixLH(pos,Target,up);

	recalculateViewArea();

	for(irr::u32 i=0; i<nodeArray.size(); ++i)
	{
		projMat.MaterialType = (irr::video::E_MATERIAL_TYPE)projTex;
		projMat.TextureLayer[0].Texture = texture;
//		projMat.TextureLayer[0].TextureWrap = ETC_CLAMP_TO_BORDER;

		pVideo->setTransform(irr::video::ETS_WORLD,nodeArray[i]->getAbsoluteTransformation());
		pVideo->setMaterial(projMat);

		for(irr::u32 j=0; j<nodeArray[i]->getMaterialCount(); ++j)
			pVideo->drawMeshBuffer(nodeArray[i]->getMesh()->getMeshBuffer(j));
	}
}

void CProjectiveTextures::recalculateProjectionMatrix()
{
	ViewArea.getTransform(irr::video::ETS_PROJECTION ).buildProjectionMatrixPerspectiveFovLH(Fovy,1.0f,1.0f,3000.0f);
}

void CProjectiveTextures::recalculateViewArea()
{
	ViewArea.cameraPosition = getAbsolutePosition();

	irr::core::matrix4 m(irr::core::matrix4::EM4CONST_NOTHING);
	m.setbyproduct_nocheck(ViewArea.getTransform(irr::video::ETS_PROJECTION),ViewArea.getTransform(irr::video::ETS_VIEW));
	ViewArea.setFrom(m, true);
}

void CProjectiveTextures::OnSetConstants(irr::video::IMaterialRendererServices* services,irr::s32 userData)
{
	if(userData == 0)
	{
		irr::core::matrix4 bias;
		bias.makeIdentity();
		bias.setTranslation(irr::core::vector3df(0.5f,0.5f,0));
		bias.setScale(irr::core::vector3df(0.5f,-0.5f,1.0f));

		irr::core::matrix4 worldViewProj;
		worldViewProj = bias * ViewArea.getTransform(irr::video::ETS_PROJECTION);
		worldViewProj *= ViewArea.getTransform(irr::video::ETS_VIEW);
		worldViewProj *= pVideo->getTransform(irr::video::ETS_WORLD);
		services->setVertexShaderConstant(reinterpret_cast<const irr::f32*>(worldViewProj.pointer()),5,4);
	}
}
