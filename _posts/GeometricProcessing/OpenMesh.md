## OpenMesh使用技巧

###1 ==【存疑】==使用OpenMesh读写模型文件(包含法向、颜色、纹理坐标等属性)
```Cpp
	Mesh mesh;
	OpenMesh::IO::Options ropt, wopt;
	mesh.request_vertex_colors();
	//ropt = OpenMesh::IO::Options::VertexColor;
	wopt = OpenMesh::IO::Options::VertexColor;
	string path_from = "./random_head/";
	string path_to = "./random_head_no_tongue/";

	if (!mesh.has_vertex_colors())
	{
		std::cout << "ERROR:Vertex Color property is not available!" << std::endl;
	}
	
	string filename_from = path_from + "_rnd_head.ply";
	string filename_to = path_to + "_rnd_head.obj";


	if (!OpenMesh::IO::read_mesh(mesh, filename_from, ropt))
	{
		std::cout << "ERROR:read " << filename_from << " failed!" << std::endl;
	}


	if (!OpenMesh::IO::write_mesh(mesh, filename_to, wopt))
	{
		std::cout << "ERROR:write " << filename_from << " failed!" << std::endl;
	}

	if (!ropt.check(OpenMesh::IO::Options::VertexColor))
	{
		std::cout << "ERROR:read " << filename_from << " vertex color failed!" << std::endl;
	}
```

###2 OpenMesh 删除顶点

```cpp
	Mesh mesh;
	vector<int> tongue;//要删除的顶点
	//让mesh具有保存顶点状态的能力
	if (!mesh.has_vertex_status())
		mesh.request_vertex_status();
	if (!mesh.has_face_status())
		mesh.request_face_status();
	if (!mesh.has_edge_status())
		mesh.request_edge_status();

	for (vector<int>::iterator it=tongue.begin(); it != tongue.end(); it++)
	{
		Mesh::VertexHandle vhandle = mesh.vertex_handle(*it);
		mesh.delete_vertex(vhandle, true);//将顶点以及邻接边邻接面标记为已删除
	}

	mesh.garbage_collection();//回首已删除顶点的内存

	if (mesh.has_vertex_status())
		mesh.release_vertex_status();
	if (mesh.has_face_status())
		mesh.release_face_status();
	if (mesh.has_edge_status())
		mesh.release_edge_status();
```