//
//  CRayTrace.cpp
//  rt
//
//  Created by Radoslaw Mantiuk on 22/01/2023.
//

#include "rt.h"


/// \fn compPrimaryRayMatrix(CCamera cam, glm::mat3& m)
/// \brief Computation of the projection matrix.
/// \param cam Camera parameters.
/// \param m Output projection matrix.
///
bool CRayTrace::compPrimaryRayMatrix(const CCamera& cam, glm::mat3& m) {
    glm::vec3 look = cam.lookp - cam.eyep;
    glm::vec3 u = glm::normalize(glm::cross(cam.up,look));
    glm::vec3 v = glm::normalize(glm::cross(u, look));
    glm::vec3 o = glm::normalize(look) * ((float)cam.width / (2.0f * tan(glm::radians(cam.fov / 2.0f)))) - ((float)cam.width/2.0f * u + (float)cam.height/2.0f * v);
    m = {u,v,o};
    return true;
}


/// \fn rayTrace(CScene scene, CRay& ray, COutput& out)
/// \brief Traces single ray.
/// \param scene Object with all scene components including a camera.
/// \param ray Ray parameter (primary and secondary rays).
/// \param out Object with output color and parameters used in recursion.
///
bool CRayTrace::rayTrace(const CScene& scene, CRay& ray, COutput& out) {

    float tmin = FLT_MAX;
    float EPS = 0.0001f;
    bool is_intersection = false;
    CObject* hit_obj;

    for(auto obj : scene.objectList) {
        float t = obj->intersect(ray);
        if(t > EPS && t < tmin) {
            tmin = t;
            is_intersection = true;
            hit_obj = obj;
        }
    }
    /*if(is_intersection == false) return false;
        glm::vec3 p = ray.pos + tmin * ray.dir;
        for(auto light : scene.lightList) {
            out.col = out.col + light.color * hit_obj->matAmbient;
            glm::vec3 n = hit_obj->normal(p);
            glm::vec3 L = glm::normalize(light.pos - p);
            float cos_angle = glm::dot(n, L);\
            if(cos_angle > 0.001) {
            out.col = out.col + light.color * hit_obj->matDiffuse * cos_angle;
            glm::vec3 h = glm::normalize(L + (-ray.dir));
            float cos_beta = glm::dot(n, h);
            if(cos_beta > 0.001){
                out.col = out.col + light.color * hit_obj->matSpecular * powf(cos_beta,hit_obj->matShininess);
            }
        } //out.col = hit_obj ->matAmbient * light.color;
    }*/

    if(is_intersection == false) return false;
    glm::vec3 p = ray.pos + tmin * ray.dir;
    glm::vec3 n = hit_obj->normal(p);
    for(auto light : scene.lightList) {
        out.col = out.col + light.color * hit_obj->matAmbient;
        CRay shadow_ray;
        shadow_ray.pos = p;
        shadow_ray.dir = glm::normalize(light.pos - p);
        float light_dist = glm::length(light.pos - p);
        bool in_shadow = false;
        for(auto obj : scene.objectList) {
            float t = obj->intersect(shadow_ray);
            if(t > EPS && t < light_dist) {
                in_shadow = true;
                break;
            }
        }
        if(in_shadow) continue;
        glm::vec3 L = shadow_ray.dir;
        float cos_angle = glm::dot(n,L);
        if(cos_angle > 0.001f){
            out.col = out.col + light.color * hit_obj->matDiffuse * cos_angle;

            glm::vec3 h = glm::normalize(L + (-ray.dir));
            float cos_beta = glm::dot(n,h);
            if(cos_beta > 0.001f){
                out.col = out.col + light.color * hit_obj->matSpecular * powf(cos_beta, hit_obj->matShininess);
            }
        }
    }


    /// looks for the closest object along the ray path
    /// returns false if there are no intersection

    /// computes 3D position of the intersection point

    /// computes normal vector at intersection point

    /// for each light source defined in the scene

        /// computes if the intersection point is in the shadows

        /// computes diffuse color component

        /// computes specular color component

    /// adds texture for textured spheres

    /// computes ambient color component

    /// if the surface is reflective

        /// if out.tree >= MAX_RAY_TREE return from function

        /// computes the secondary ray parameters (reflected ray)

        /// recursion
        //   rayTrace(scene, secondary_ray, out);


    return true;
}


/// \fn reflectedRay(CRay ray, glm::vec3 n, glm::vec3 pos)
/// \brief Computes parameters of the ray reflected at the surface point with given normal vector.
/// \param ray Input ray.
/// \param n Surface normal vector.
/// \param pos Position of reflection point.
/// \return Reflected ray.
///
CRay CRayTrace::reflectedRay(const CRay& ray, const glm::vec3& n, const glm::vec3& pos) {
    CRay reflected_ray;
    
    return reflected_ray;
}

