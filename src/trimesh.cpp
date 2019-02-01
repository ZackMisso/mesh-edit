#include <mesh-edit/trimesh.h>

namespace mesh_edit
{

Tri::Tri()
{
    vert_inds = std::vector<uint32_t>();
    norm_ints = std::vector<uint32_t>();
    uv_inds = std::vector<uint32_t>();
}

Tri::Tri(const std::vector<uint32_t>& vs,
         const std::vector<uint32_t>& ns,
         const std::vector<uint32_t>& uvs)
    : vert_inds(vs), norm_inds(ns), uv_inds(uvs);
{
}

Trimesh::Trimesh()
{
    vs = std::vector<Vec3>();
    vts = std::vector<Vec3>();
    uvs = std::vector<Vec3>();
    ns = std::vector<Vec3>();
    tris = std::vector<Vec3>();
}

void Trimesh::loadFromFile(std::string filename)
{
    // TODO
}

void Trimesh::writeToFile(std::string filename) const
{
    // TODO
}

Vec3 Trimesh::center() const
{
    Vec3 center = Vec3();

    for (int i = 0; i < vs.size(); ++i)
    {
        center = center + vs[i];
    }

    center.x /= double(vs.size());
    center.y /= double(vs.size());
    center.z /= double(vs.size());

    return center;
}

void Trimesh::operator+=(const Vec3& val)
{
    for (int i = 0; i < vs.size(); ++i)
    {
        vs[i].x += val.x;
        vs[i].y += val.y;
        vs[i].z += val.z;
    }
}

void Trimesh::operator-=(const Vec3& val)
{
    for (int i = 0; i < vs.size(); ++i)
    {
        vs[i].x -= val.x;
        vs[i].y -= val.y;
        vs[i].z -= val.z;
    }
}

void Trimesh::operator*=(const Vec3& val)
{
    for (int i = 0; i < vs.size(); ++i)
    {
        vs[i].x *= val.x;
        vs[i].y *= val.y;
        vs[i].z *= val.z;
    }
}

void Trimesh::operator/=(const Vec3& val)
{
    for (int i = 0; i < vs.size(); ++i)
    {
        vs[i].x /= val.x;
        vs[i].y /= val.y;
        vs[i].z /= val.z;
    }
}

const std::vector<Vec3>& Trimesh::getVs() const
{
    return vs;
}

const std::vector<Vec3>& Trimesh::getVts() const
{
    return vts;
}

const std::vector<Vec3>& Trimesh::getUVs() const
{
    return uvs;
}

const std::vector<Vec3>& Trimesh::getNs() const
{
    return ns;
}

const std::vector<Tri>& Trimesh::getTris() const
{
    return tris;
}

}
