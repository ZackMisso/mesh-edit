#pragma once

namespace mesh_edit
{

struct Tri
{
    Tri();

    Tri(const std::vector<uint32_t>& vs,
        const std::vector<uint32_t>& ns,
        const std::vector<uint32_t>& uvs);

    std::vector<uint32_t> vert_inds;
    std::vector<uint32_t> norm_inds;
    std::vector<uint32_t> uv_inds;
};

class Trimesh
{
public:
    Trimesh();

    void loadFromFile(std::string filename);
    void writeToFile(std::string filename) const;

    Vec3 center() const;

    void operator+=(const Vec3& val);
    void operator-=(const Vec3& val);
    void operator*=(const Vec3& val);
    void operator/=(const Vec3& val);

    const std::vector<Vec3>& getVs() const;
    const std::vector<Vec3>& getVts() const;
    const std::vector<Vec3>& getUVs() const;
    const std::vector<Vec3>& getNs() const;
    const std::vector<Tri>& getTris() const;

protected:
    std::vector<Vec3> vs;
    std::vector<Vec3> vts;
    std::vector<Vec3> uvs;
    std::vector<Vec3> ns;

    std::vector<Tri> tris;
};

}
