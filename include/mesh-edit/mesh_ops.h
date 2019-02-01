#pragma once

#include <mesh-edit/common.h>
#include <mesh-edit/trimesh.h>

namespace mesh_edit
{

void center_mesh(Trimesh& mesh, Vec3 new_center)
{
    Vec3 currentCenter = mesh.center();
    Vec3 translate = new_center - currentCenter;
    mesh += translate;
}

int min_dimension(Trimesh& mesh, double& value)
{
    Vec3 min = Vec3(1e10, 1e10, 1e10);

    const std::vector<Vec3>& vs = mesh.getVs();

    for (int i = 0; i < vs.size(); ++i)
    {
        if (vs[i].x < min.x) min.x = vs[i].x;
        if (vs[i].y < min.y) min.y = vs[i].y;
        if (vs[i].z < min.z) min.z = vs[i].z;
    }

    if (min.x < min.y && min.x < min.z)
    {
        value = min.x;
        return 0;
    }

    if (min.y < min.z)
    {
        value = min.y;
        return 1;
    }

    value = min.z;
    return 2;
}

int max_dimension(Trimesh& mesh, double& value)
{
    Vec3 max = Vec3(-1e10, -1e10, -1e10);

    const std::vector<Vec3>& vs = mesh.getVs();

    for (int i = 0; i < vs.size(); ++i)
    {
        if (vs[i].x > max.x) max.x = vs[i].x;
        if (vs[i].y > max.y) max.y = vs[i].y;
        if (vs[i].z > max.z) max.z = vs[i].z;
    }

    if (max.x > max.y && max.x > max.z)
    {
        value = max.x;
        return 0;
    }

    if (max.y > max.z)
    {
        value = max.y;
        return 1;
    }

    value = max.z;
    return 2;
}

double min_along_dimension(Trimesh& mesh, int dim)
{
    double min = 1e10;

    const std::vector<Vec3>& vs = mesh.getVs();

    for (int i = 0; i < vs.size(); ++i)
    {
        if (dim == 0) if (vs[i].x < min) min = vs[i].x;
        if (dim == 1) if (vs[i].y < min) min = vs[i].y;
        if (dim == 2) if (vs[i].z < min) min = vs[i].z;
    }

    return min;
}

double max_along_dimension(Trimesh& mesh, int dim)
{
    double max = -1e10;

    const std::vector<Vec3>& vs = mesh.getVs();

    for (int i = 0; i < vs.size(); ++i)
    {
        if (dim == 0) if (vs[i].x > max) max = vs[i].x;
        if (dim == 1) if (vs[i].y > max) max = vs[i].y;
        if (dim == 2) if (vs[i].z > max) max = vs[i].z;
    }

    return max;
}

void align_mesh_base(Trimesh& mesh, Vec3 point)
{
    // TODO
}

void align_mesh_top(Trimesh& mesh, Vec3 point)
{
    // TODO
}

}
