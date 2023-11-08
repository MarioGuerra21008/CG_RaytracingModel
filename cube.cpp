#include "cube.h"

Cube::Cube(const glm::vec3& min, const glm::vec3& max, const Material& mat)
        : min(min), max(max), Object(mat) {}

Intersect Cube::rayIntersect(const glm::vec3& rayOrigin, const glm::vec3& rayDirection) const {
    glm::vec3 tmin = (min - rayOrigin) / rayDirection;
    glm::vec3 tmax = (max - rayOrigin) / rayDirection;

    glm::vec3 real_min = glm::min(tmin, tmax);
    glm::vec3 real_max = glm::max(tmin, tmax);

    float tmin_final = glm::max(glm::max(real_min.x, real_min.y), real_min.z);
    float tmax_final = glm::min(glm::min(real_max.x, real_max.y), real_max.z);

    if (tmin_final > tmax_final || tmax_final < 0) {
        return Intersect{false};
    }

    glm::vec3 point = rayOrigin + tmin_final * rayDirection;

    // Calculate the normal based on the face that was hit
    glm::vec3 normal(0.0f);

    if (tmin_final == real_min.x) {
        normal = glm::vec3(-1.0f, 0.0f, 0.0f);
    } else if (tmin_final == real_min.y) {
        normal = glm::vec3(0.0f, -1.0f, 0.0f);
    } else if (tmin_final == real_min.z) {
        normal = glm::vec3(0.0f, 0.0f, -1.0f);
    } else if (tmin_final == real_max.x) {
        normal = glm::vec3(1.0f, 0.0f, 0.0f);
    } else if (tmin_final == real_max.y) {
        normal = glm::vec3(0.0f, 1.0f, 0.0f);
    } else if (tmin_final == real_max.z) {
        normal = glm::vec3(0.0f, 0.0f, 1.0f);
    }

    return Intersect{true, tmin_final, point, normal};
}