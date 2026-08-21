#ifndef RC_MESH_H_INCLUDED
#define RC_MESH_H_INCLUDED

//load a mesh from a file
int rc_loadMesh(std::string mesh_file)
{
    int mesh_id = -1;

    rc_mesh_obj mesh_obj;
    mesh_obj.mesh_type = RC_MESH_TYPE_ANIMATED;

    irr::scene::IAnimatedMesh* mesh = SceneManager->getMesh(mesh_file.c_str());
    mesh_obj.mesh = mesh;

    if(!mesh)
        return -1;

    for(int i = 0; i < rc_mesh.size(); i++)
    {
        if(!rc_mesh[i].mesh)
        {
            mesh_id = i;
            break;
        }
    }

    if(mesh_id < 0)
    {
        mesh_id = rc_mesh.size();
        rc_mesh.push_back(mesh_obj);
    }
    else
    {
        rc_mesh[mesh_id] = mesh_obj;
    }

    return mesh_id;
}

//load a mesh from an archive
int rc_loadMeshFromArchive(std::string archive, std::string mesh_file)
{
	int mesh_id = -1;

	device->getFileSystem()->addFileArchive(archive.c_str());
	irr::scene::IAnimatedMesh *mesh = SceneManager->getMesh(mesh_file.c_str());
	device->getFileSystem()->removeFileArchive((irr::u32) 0);

	rc_mesh_obj mesh_obj;
    mesh_obj.mesh_type = RC_MESH_TYPE_ANIMATED;
    mesh_obj.mesh = mesh;

	if(!mesh)
        return -1;

    for(int i = 0; i < rc_mesh.size(); i++)
    {
        if(!rc_mesh[i].mesh)
        {
            mesh_id = i;
            break;
        }
    }

    if(mesh_id < 0)
    {
        mesh_id = rc_mesh.size();
        rc_mesh.push_back(mesh_obj);
    }
    else
    {
        rc_mesh[mesh_id] = mesh_obj;
    }

    return mesh_id;
}


void rc_setMeshBoundingBox(int mesh_id, double min_x, double min_y, double min_z, double max_x, double max_y, double max_z)
{
    if(mesh_id < 0 || mesh_id >= rc_mesh.size())
        return;

    if(rc_mesh[mesh_id].mesh)
    {
        rc_mesh[mesh_id].mesh->setBoundingBox( irr::core::aabbox3df(min_x, min_y, min_z, max_x, max_y, max_z) );
    }
}

void rc_getMeshBoundingBox(int mesh_id, double* min_x, double* min_y, double* min_z, double* max_x, double* max_y, double* max_z)
{
    if(mesh_id < 0 || mesh_id >= rc_mesh.size())
        return;

    if(rc_mesh[mesh_id].mesh)
    {
        irr::core::aabbox3df bbox = rc_mesh[mesh_id].mesh->getBoundingBox();

        *min_x = bbox.MinEdge.X;
        *min_y = bbox.MinEdge.Y;
        *min_z = bbox.MinEdge.Z;

        *max_x = bbox.MaxEdge.X;
        *max_y = bbox.MaxEdge.Y;
        *max_z = bbox.MaxEdge.Z;
    }
}

void rc_reCalculateMeshBoundingBox(int mesh_id)
{
    if(mesh_id < 0 || mesh_id >= rc_mesh.size())
        return;

    if(rc_mesh[mesh_id].mesh)
    {
        for(int i = 0; i < rc_mesh[mesh_id].mesh->getMeshBufferCount(); i++)
            rc_mesh[mesh_id].mesh->getMeshBuffer(i)->recalculateBoundingBox();
    }
}

void rc_reCalculateMeshNormals(int mesh_id)
{
    if(mesh_id < 0 || mesh_id >= rc_mesh.size())
        return;

    if(rc_mesh[mesh_id].mesh)
    {
        for(int i = 0; i < rc_mesh[mesh_id].mesh->getMeshBufferCount(); i++)
            SceneManager->getMeshManipulator()->recalculateNormals(rc_mesh[mesh_id].mesh->getMeshBuffer(i));
    }
}

void rc_makePlanarTextureMap(int mesh_id, double resolution)
{
    if(mesh_id < 0 || mesh_id >= rc_mesh.size())
        return;

    if(rc_mesh[mesh_id].mesh)
    {
        for(int i = 0; i < rc_mesh[mesh_id].mesh->getMeshBufferCount(); i++)
            SceneManager->getMeshManipulator()->makePlanarTextureMapping(rc_mesh[mesh_id].mesh->getMeshBuffer(i), resolution);
    }
}

int rc_getMeshPolygonCount(int mesh_id)
{
    if(mesh_id < 0 || mesh_id >= rc_mesh.size())
        return 0;

    if(rc_mesh[mesh_id].mesh)
    {
        if(rc_mesh[mesh_id].mesh_type == RC_MESH_TYPE_ANIMATED)
            return SceneManager->getMeshManipulator()->getPolyCount((irr::scene::IAnimatedMesh*)rc_mesh[mesh_id].mesh);
        else
            return SceneManager->getMeshManipulator()->getPolyCount(rc_mesh[mesh_id].mesh);
    }
}

void rc_flipMeshSurfaces(int mesh_id)
{
    if(mesh_id < 0 || mesh_id >= rc_mesh.size())
        return;

    if(rc_mesh[mesh_id].mesh)
    {
        SceneManager->getMeshManipulator()->flipSurfaces(rc_mesh[mesh_id].mesh);
    }
}



int rc_loadAN8(std::string an8_file)
{
	int id = -1;

	for(int i = 0; i < rc_an8.size(); i++)
	{
		if(!rc_an8[i].active)
		{
			id = i;
			break;
		}
	}

	if(id < 0)
	{
		id = rc_an8.size();
		rc_an8_obj obj;
		rc_an8.push_back(obj);
	}

	rc_an8[id].project = an8::loadAN8(an8_file);
	if(rc_an8[id].project.exists)
	{
		rc_an8[id].active = true;
		return id;
	}

	rc_an8[id].active = false;

	return -1;
}

//load a mesh from an archive
int rc_loadMeshFromAN8(int an8_id, std::string scene_name)
{
	int mesh_id = -1;

	if(an8_id < 0 || an8_id >= rc_an8.size())
		return -1;

	if(!rc_an8[an8_id].active)
		return -1;

	rc_mesh_obj mesh_obj;
    mesh_obj.mesh_type = RC_MESH_TYPE_ANIMATED;
    mesh_obj.mesh = an8::loadAN8Scene(device, rc_an8[an8_id].project, scene_name);

	if(!mesh_obj.mesh)
        return -1;

    for(int i = 0; i < rc_mesh.size(); i++)
    {
        if(!rc_mesh[i].mesh)
        {
            mesh_id = i;
            break;
        }
    }

    if(mesh_id < 0)
    {
        mesh_id = rc_mesh.size();
        rc_mesh.push_back(mesh_obj);
    }
    else
    {
        rc_mesh[mesh_id] = mesh_obj;
    }

    return mesh_id;
}

int rc_getNumAN8Scenes(int an8_id)
{
	if(an8_id < 0 || an8_id >= rc_an8.size())
		return 0;

	if(!rc_an8[an8_id].active)
		return 0;

	return rc_an8[an8_id].project.scenes.size();
}

std::string rc_getAN8SceneName(int an8_id, int scene_num)
{
	if(an8_id < 0 || an8_id >= rc_an8.size())
		return "";

	if(!rc_an8[an8_id].active)
		return "";

	if(scene_num < 0 || scene_num >= rc_an8[an8_id].project.scenes.size())
		return "";

	return rc_an8[an8_id].project.scenes[scene_num].name;
}

void rc_deleteAN8(int an8_id)
{
	if(an8_id < 0 || an8_id >= rc_an8.size())
		return;

	rc_an8[an8_id].active = false;
}

//delete mesh
void rc_deleteMesh(int mesh_id)
{
    if(mesh_id < 0 || mesh_id >= rc_mesh.size())
        return;

    if(rc_mesh[mesh_id].mesh)
	{
		if(rc_mesh[mesh_id].mesh->getReferenceCount() > 0)
		{
			SceneManager->getMeshCache()->removeMesh(rc_mesh[mesh_id].mesh);
		}
	}

    rc_mesh[mesh_id].mesh = NULL;
    rc_mesh[mesh_id].mesh_type = 0;

}

//create mesh from geometry data [TODO]
int rc_createMesh()
{
    irr::scene::ISkinnedMesh * mesh = SceneManager->createSkinnedMesh();

    if(!mesh)
        return -1;

    int mesh_id = rc_mesh.size();
    rc_mesh_obj mesh_obj;
    mesh_obj.mesh = mesh;
    mesh_obj.mesh_type = RC_MESH_TYPE_ANIMATED;

    rc_mesh.push_back(mesh_obj);

    return mesh_id;
}

int rc_createPlaneMesh(double w, double h, double tileCount_w, double tileCount_h, double txRepeat_x, double txRepeat_y)
{
	const irr::scene::IGeometryCreator* gc = SceneManager->getGeometryCreator();

	irr::scene::IMesh* mesh = gc->createPlaneMesh(irr::core::dimension2d<irr::f32>((irr::f32)w, (irr::f32)h),
														  irr::core::dimension2d<irr::u32>((irr::u32)tileCount_w, (irr::u32)tileCount_h), 0,
														  irr::core::dimension2d<irr::f32>((irr::f32)txRepeat_x, (irr::f32)txRepeat_y));

    if(!mesh)
        return -1;

    int mesh_id = rc_mesh.size();
    rc_mesh_obj mesh_obj;
    mesh_obj.mesh = mesh;
    mesh_obj.mesh_type = RC_MESH_TYPE_NONE;

    rc_mesh.push_back(mesh_obj);

    return mesh_id;
}


int rc_createConeMesh( double radius, double cone_length, double tesselation, double top_color, double bottom_color )
{
	const irr::scene::IGeometryCreator* gc = SceneManager->getGeometryCreator();

	irr::scene::IMesh* mesh = gc->createConeMesh( (irr::f32)radius, (irr::f32)cone_length, (irr::u32)tesselation,
												   irr::video::SColor((irr::u32)top_color), irr::video::SColor((irr::u32)bottom_color) );

    if(!mesh)
        return -1;

    int mesh_id = rc_mesh.size();
    rc_mesh_obj mesh_obj;
    mesh_obj.mesh = mesh;
    mesh_obj.mesh_type = RC_MESH_TYPE_NONE;

    rc_mesh.push_back(mesh_obj);

    return mesh_id;
}


int rc_createCylinderMesh( double radius, double cylinder_length, double tesselation, double color, double close_top )
{
	const irr::scene::IGeometryCreator* gc = SceneManager->getGeometryCreator();

	irr::scene::IMesh* mesh = gc->createCylinderMesh( (irr::f32)radius, (irr::f32)cylinder_length, (irr::u32)tesselation,
												   irr::video::SColor((irr::u32)color), (close_top == 0 ? false : true) );

    if(!mesh)
        return -1;

    int mesh_id = rc_mesh.size();
    rc_mesh_obj mesh_obj;
    mesh_obj.mesh = mesh;
    mesh_obj.mesh_type = RC_MESH_TYPE_NONE;

    rc_mesh.push_back(mesh_obj);

    return mesh_id;
}


int rc_createVolumeLightMesh( double u, double v, double foot_color, double tail_color, double lp_distance, double dim_x, double dim_y, double dim_z )
{
	const irr::scene::IGeometryCreator* gc = SceneManager->getGeometryCreator();

	irr::scene::IMesh* mesh = gc->createVolumeLightMesh( (irr::u32)u, (irr::u32)v, irr::video::SColor((irr::u32)foot_color),
												   irr::video::SColor((irr::u32)tail_color), (irr::f32)lp_distance,
												   irr::core::vector3df((irr::f32)dim_x, (irr::f32)dim_y, (irr::f32)dim_z) );

    if(!mesh)
        return -1;

    int mesh_id = rc_mesh.size();
    rc_mesh_obj mesh_obj;
    mesh_obj.mesh = mesh;
    mesh_obj.mesh_type = RC_MESH_TYPE_NONE;

    rc_mesh.push_back(mesh_obj);

    return mesh_id;
}


//create mesh from geometry data [TODO]
int rc_addMeshBuffer(int mesh_id, int vertex_count, double* vertex_data, double* normal_data, double* uv_data, int index_count, double* index_data)
{
    irr::scene::ISkinnedMesh * mesh = (irr::scene::ISkinnedMesh*) rc_mesh[mesh_id].mesh;

    irr::scene::SSkinMeshBuffer* mbuf = mesh->addMeshBuffer();

    if(!mbuf)
    {
        mesh->drop();
        return -1;
    }

    irr::core::array<irr::video::S3DVertex> vertices;
    irr::core::array<irr::u16> indices;

    for(int i = 0; i < vertex_count; i++)
    {
        irr::video::S3DVertex v;
        v.Pos = irr::core::vector3df( (irr::f32) vertex_data[i*3], (irr::f32) vertex_data[i*3+1], (irr::f32) vertex_data[i*3+2] );
        v.Normal = irr::core::vector3df( (irr::f32) normal_data[i*3], (irr::f32) normal_data[i*3+1], (irr::f32) normal_data[i*3+2] );
        v.TCoords = irr::core::vector2df( (irr::f32) uv_data[i*2], (irr::f32) uv_data[i*2+1] );
        vertices.push_back(v);
    }

    for(int i = 0; i < index_count; i++)
    {
        indices.push_back( (irr::u16) index_data[i] );
    }

    if(indices.size() > 0)
    {
        for(int i = 0; i < vertices.size(); i++)
            mbuf->Vertices_Standard.push_back(vertices[i]);

        for(int i = 0; i < indices.size(); i++)
            mbuf->Indices.push_back(indices[i]);

    }

    int mbuf_index = mesh->getMeshBufferCount()-1;

    return mbuf_index;
}


bool rc_setMeshBuffer(int mesh_id, int buffer_index, int vertex_count, double* vertex_data, double* normal_data, double* uv_data, int index_count, double* index_data)
{
    irr::scene::ISkinnedMesh * mesh = (irr::scene::ISkinnedMesh*) rc_mesh[mesh_id].mesh;

    if(buffer_index < 0 || buffer_index >= mesh->getMeshBufferCount())
        return false;

    irr::scene::SSkinMeshBuffer* mbuf = (irr::scene::SSkinMeshBuffer*)mesh->getMeshBuffer(buffer_index);

    if(!mbuf)
    {
        mesh->drop();
        return false;
    }

    irr::core::array<irr::video::S3DVertex> vertices;
    irr::core::array<irr::u16> indices;

    for(int i = 0; i < vertex_count; i++)
    {
        irr::video::S3DVertex v;
        v.Pos = irr::core::vector3df( (irr::f32) vertex_data[i*3], (irr::f32) vertex_data[i*3+1], (irr::f32) vertex_data[i*3+2] );
        v.Normal = irr::core::vector3df( (irr::f32) normal_data[i*3], (irr::f32) normal_data[i*3+1], (irr::f32) normal_data[i*3+2] );
        v.TCoords = irr::core::vector2df( (irr::f32) uv_data[i*2], (irr::f32) uv_data[i*2+1] );
        vertices.push_back(v);
    }

    for(int i = 0; i < index_count; i++)
    {
        indices.push_back( (irr::u16) index_data[i] );
    }

    if(indices.size() > 0)
    {
        mbuf->Indices.clear();
        mbuf->Vertices_Standard.clear();

        for(int i = 0; i < vertices.size(); i++)
            mbuf->Vertices_Standard.push_back(vertices[i]);

        for(int i = 0; i < indices.size(); i++)
            mbuf->Indices.push_back(indices[i]);

    }

    return true;
}


int rc_getMeshBufferCount(int mesh_id)
{
    irr::scene::ISkinnedMesh * mesh = (irr::scene::ISkinnedMesh*) rc_mesh[mesh_id].mesh;

    if(mesh_id < 0 || mesh_id >= rc_mesh.size())
        return false;

    return rc_mesh[mesh_id].mesh->getMeshBufferCount();
}

int rc_getMeshBufferVertexCount(int mesh_id, int buffer_index)
{
    irr::scene::ISkinnedMesh * mesh = (irr::scene::ISkinnedMesh*) rc_mesh[mesh_id].mesh;

    if(mesh_id < 0 || mesh_id >= rc_mesh.size())
        return 0;

    int buffer_count = rc_mesh[mesh_id].mesh->getMeshBufferCount();

    if(buffer_index < 0 || buffer_index >= buffer_count)
        return 0;

    irr::scene::SSkinMeshBuffer* mbuf = (irr::scene::SSkinMeshBuffer*)mesh->getMeshBuffer(buffer_index);

    if(!mbuf)
    {
        return 0;
    }

    return mbuf->getVertexCount();
}

int rc_getMeshBufferIndexCount(int mesh_id, int buffer_index)
{
    irr::scene::ISkinnedMesh * mesh = (irr::scene::ISkinnedMesh*) rc_mesh[mesh_id].mesh;

    if(mesh_id < 0 || mesh_id >= rc_mesh.size())
        return 0;

    int buffer_count = rc_mesh[mesh_id].mesh->getMeshBufferCount();

    if(buffer_index < 0 || buffer_index >= buffer_count)
        return 0;

    irr::scene::SSkinMeshBuffer* mbuf = (irr::scene::SSkinMeshBuffer*)mesh->getMeshBuffer(buffer_index);

    if(!mbuf)
    {
        return 0;
    }

    return mbuf->getIndexCount();
}

bool rc_getMeshBuffer(int mesh_id, int buffer_index, double* vertex_data, double* normal_data, double* uv_data, double* index_data)
{
    irr::scene::ISkinnedMesh * mesh = (irr::scene::ISkinnedMesh*) rc_mesh[mesh_id].mesh;

    if(mesh_id < 0 || mesh_id >= rc_mesh.size())
        return false;

    int buffer_count = rc_mesh[mesh_id].mesh->getMeshBufferCount();

    if(buffer_index < 0 || buffer_index >= buffer_count)
        return false;

    irr::scene::SSkinMeshBuffer* mbuf = (irr::scene::SSkinMeshBuffer*)mesh->getMeshBuffer(buffer_index);

    if(!mbuf)
    {
        return false;
    }

    int vertex_count = mbuf->getVertexCount();
    int index_count = mbuf->getIndexCount();

    for(int i = 0; i < vertex_count; i++)
    {
        irr::video::S3DVertex* v = mbuf->getVertex(i);

        vertex_data[i*3]   = (double)v->Pos.X;
        vertex_data[i*3+1] = (double)v->Pos.Y;
        vertex_data[i*3+2] = (double)v->Pos.Z;

        normal_data[i*3]   = (double)v->Normal.X;
        normal_data[i*3+1] = (double)v->Normal.Y;
        normal_data[i*3+2] = (double)v->Normal.Z;

        uv_data[i*2]   = (double)v->TCoords.X;
        uv_data[i*2+1] = (double)v->TCoords.Y;
    }

    for(int i = 0; i < index_count; i++)
    {
        index_data[i] = (double)mbuf->getIndices()[i];
    }

    return true;
}

int rc_getMeshFrameCount(int mesh_id)
{
    if(mesh_id < 0 || mesh_id >= rc_mesh.size())
        return 0;

    int frame_count = 0;

    switch(rc_mesh[mesh_id].mesh_type)
    {
        case RC_MESH_TYPE_ANIMATED:
        {
            irr::scene::IAnimatedMesh * mesh = (irr::scene::IAnimatedMesh*) rc_mesh[mesh_id].mesh;
            frame_count = mesh->getFrameCount();
        }
        break;
    }

    return frame_count;
}


#endif // RC_MESH_H_INCLUDED
