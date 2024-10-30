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

//delete mesh
void rc_deleteMesh(int mesh_id)
{
    if(mesh_id < 0 || mesh_id >= rc_mesh.size())
        return;

    if(rc_mesh[mesh_id].mesh)
        rc_mesh[mesh_id].mesh->drop();

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

int rc_createPlaneMesh(double w, double h, double tileCount_w, double tileCount_h)
{
	irr::scene::IAnimatedMesh* mesh = SceneManager->addHillPlaneMesh( "plane",
																irr::core::dimension2d<irr::f32>(w/tileCount_w, h/tileCount_h),
																irr::core::dimension2d<irr::u32>(tileCount_w, tileCount_h));

    if(!mesh)
        return -1;

    int mesh_id = rc_mesh.size();
    rc_mesh_obj mesh_obj;
    mesh_obj.mesh = mesh;
    mesh_obj.mesh_type = RC_MESH_TYPE_ANIMATED;

    rc_mesh.push_back(mesh_obj);

    return mesh_id;
}


//create mesh from geometry data [TODO]
bool rc_addMeshBuffer(int mesh_id, int vertex_count, double* vertex_data, double* normal_data, double* uv_data, int index_count, double* index_data)
{
    irr::scene::ISkinnedMesh * mesh = (irr::scene::ISkinnedMesh*) rc_mesh[mesh_id].mesh;

    irr::scene::SSkinMeshBuffer* mbuf = mesh->addMeshBuffer();

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
        for(int i = 0; i < vertices.size(); i++)
            mbuf->Vertices_Standard.push_back(vertices[i]);

        for(int i = 0; i < indices.size(); i++)
            mbuf->Indices.push_back(indices[i]);

    }

    return true;
}

#endif // RC_MESH_H_INCLUDED
