#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>

namespace fs = std::filesystem;

struct Vec3 {
    float x, y, z;
};

struct Mesh {
    std::vector<Vec3> vertices;
    std::vector<std::vector<int>> faces;
    Vec3 minBound, maxBound;
};

Mesh loadOBJ(const std::string& filename) {
    Mesh mesh;
    std::ifstream file(filename);
    std::string line;

    mesh.minBound = { std::numeric_limits<float>::max(), std::numeric_limits<float>::max(), std::numeric_limits<float>::max() };
    mesh.maxBound = { std::numeric_limits<float>::lowest(), std::numeric_limits<float>::lowest(), std::numeric_limits<float>::lowest() };

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "v") {
            Vec3 v;
            iss >> v.x >> v.y >> v.z;
            mesh.vertices.push_back(v);
            mesh.minBound.x = std::min(mesh.minBound.x, v.x);
            mesh.minBound.y = std::min(mesh.minBound.y, v.y);
            mesh.minBound.z = std::min(mesh.minBound.z, v.z);
            mesh.maxBound.x = std::max(mesh.maxBound.x, v.x);
            mesh.maxBound.y = std::max(mesh.maxBound.y, v.y);
            mesh.maxBound.z = std::max(mesh.maxBound.z, v.z);
        } else if (type == "f") {
            std::vector<int> face;
            int idx;
            while (iss >> idx) {
                face.push_back(idx);
            }
            mesh.faces.push_back(face);
        }
    }

    return mesh;
}

void displayMeshStats(const Mesh& mesh) {
    std::cout << "Loaded Mesh Stats:" << std::endl;
    std::cout << "Vertices: " << mesh.vertices.size() << std::endl;
    std::cout << "Faces:    " << mesh.faces.size() << std::endl;
    std::cout << "Bounding Box:" << std::endl;
    std::cout << "  Min: (" << mesh.minBound.x << ", " << mesh.minBound.y << ", " << mesh.minBound.z << ")" << std::endl;
    std::cout << "  Max: (" << mesh.maxBound.x << ", " << mesh.maxBound.y << ", " << mesh.maxBound.z << ")" << std::endl;
}

int main(int argc, char* argv[]) {
    std::cout << "Impellor V3 Build Triggered!" << std::endl;

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <mesh_file.obj>" << std::endl;
        return 1;
    }

    std::string filepath = argv[1];
    if (!fs::exists(filepath)) {
        std::cerr << "File not found: " << filepath << std::endl;
        return 1;
    }

    Mesh mesh = loadOBJ(filepath);
    displayMeshStats(mesh);

    return 0;
}
