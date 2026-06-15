//
//  CScene.cpp
//  rt
//
//  Created by Radoslaw Mantiuk on 22/01/2023.
//

#include "rt.h"

#include<fstream>

/// \fn create(void)
/// \brief Adds components to the scene.
///
void CScene::create() {

    lightList.clear(); // clears vector with the light data
    objectList.clear(); // clears vector of pointers to objects
    
    // add camera, light sources, and objects
    cam.eyep = {0,0,10};
    cam.lookp = {0,0,0};
    cam.up = {0,1,0};
    cam.fov = 50.0f;
    cam.width = 500;
    cam.height = 400;

    CLight light1(glm::vec3(-3,-2,8));
    light1.color = {0.6,0.6,0.6};
    lightList.push_back(light1);


    CSphere* sphere1 = new CSphere({-1,0,3}, 0.4);
    sphere1->matAmbient = glm::vec3 {0,0.1,0};
    sphere1->matDiffuse = glm::vec3 {0,0.6,0};
    sphere1->matSpecular = glm::vec3 {0.7,0.7,0.7};
    sphere1->matShininess = 30;
    sphere1->reflectance = 0;
    sphere1->isTexture = 0;
    objectList.push_back((sphere1));

    CSphere* sphere2 = new CSphere({0,0,0}, 1.6);
    sphere2->matAmbient = glm::vec3 {0.1,0,0};
    sphere2->matDiffuse = glm::vec3 {0.6,0,0};
    sphere2->matSpecular = glm::vec3 {0.7,0.7,0.7};
    sphere2->matShininess = 30;
    sphere2->reflectance = 0;
    sphere2->isTexture = 0;
    objectList.push_back((sphere2));

    CSphere* sphere3 = new CSphere({-3,-2,-2}, 0.6);
    sphere3->matAmbient = glm::vec3 {0,0,0.1};
    sphere3->matDiffuse = glm::vec3 {0,0,0.6};
    sphere3->matSpecular = glm::vec3 {0.7,0.7,0.7};
    sphere3->matShininess = 30;
    sphere3->reflectance = 0;
    sphere3->isTexture = 0;
    objectList.push_back((sphere3));

    CTriangle* triangle1 = new CTriangle({5,5,-5},{-5,5,-5},{-5,-5,-5});
    triangle1->matAmbient = glm::vec3 {0.1,0.1,0.1};
    triangle1->matDiffuse = glm::vec3 {0.4,0.4,0.4};
    triangle1->matSpecular = glm::vec3 {0,0,0};
    triangle1->matShininess = 0;
    triangle1->reflectance = 0;
    objectList.push_back(triangle1);

    CTriangle* triangle2 = new CTriangle({5,5,-5},{-5,-5,-5},{5,-5,-5});
    triangle2->matAmbient = glm::vec3 {0.1,0.1,0.1};
    triangle2->matDiffuse = glm::vec3 {0.4,0.4,0.4};
    triangle2->matSpecular = glm::vec3 {0,0,0};
    triangle2->matShininess = 0;
    triangle2->reflectance = 0;
    objectList.push_back(triangle2);

    /*CSphere* sphere1 = new CSphere({0,0,0}, 1.6);
    sphere1->matAmbient = glm::vec3 {0.5,0,0};
    sphere1->matDiffuse = glm::vec3 {0,0,0};
    sphere1->matSpecular = glm::vec3 {0,0,0};
    sphere1->matShininess = 30;
    sphere1->reflectance = 0;
    sphere1->isTexture = 0;
    objectList.push_back((sphere1));*/

    /*CSphere* sphere1 = new CSphere({0,0,0}, 1.6);
    sphere1->matAmbient = glm::vec3 {0,0,0};
    sphere1->matDiffuse = glm::vec3 {0.7,0,0};
    sphere1->matSpecular = glm::vec3 {0,0,0};
    sphere1->matShininess = 0;
    sphere1->reflectance = 0;
    sphere1->isTexture = 0;
    objectList.push_back((sphere1));*/

    /*CSphere* sphere1 = new CSphere({0,0,0}, 1.6);
    sphere1->matAmbient = glm::vec3 {0,0,0};
    sphere1->matDiffuse = glm::vec3 {0,0,0};
    sphere1->matSpecular = glm::vec3 {0.7,0.7,0.7};
    sphere1->matShininess = 30;
    sphere1->reflectance = 0;
    sphere1->isTexture = 0;
    objectList.push_back((sphere1));*/

    /*CSphere* sphere1 = new CSphere({0,0,0}, 1.6);
    sphere1->matAmbient = glm::vec3 {0.1,0,0};
    sphere1->matDiffuse = glm::vec3 {0.6,0,0};
    sphere1->matSpecular = glm::vec3 {0.7,0.7,0.7};
    sphere1->matShininess = 30;
    sphere1->reflectance = 0;
    sphere1->isTexture = 0;
    objectList.push_back((sphere1));*/

    /*CSphere* sphere1 = new CSphere({0,0,0}, 1.6);
    sphere1->matAmbient = glm::vec3 {0.1,0,0};
    sphere1->matDiffuse = glm::vec3 {0.6,0,0};
    sphere1->matSpecular = glm::vec3 {0.7,0.7,0.7};
    sphere1->matShininess = 10;
    sphere1->reflectance = 0;
    sphere1->isTexture = 0;
    objectList.push_back((sphere1));*/

    /*CSphere* sphere1 = new CSphere({0,0,0}, 1.6);
    sphere1->matAmbient = glm::vec3 {0.1,0,0};
    sphere1->matDiffuse = glm::vec3 {0.6,0,0};
    sphere1->matSpecular = glm::vec3 {0.7,0.7,0.7};
    sphere1->matShininess = 50;
    sphere1->reflectance = 0;
    sphere1->isTexture = 0;
    objectList.push_back((sphere1));*/



    //std::vector<CObject*> objectList;
    //CSphere* sphere0 = new CSphere({-2.5,1.3,-3}, 1.0);
    //objectList.push_back(sphere0);

    //CSphere* sphere1 = new CSphere({0.0,0.0,0.0}, 1.6);
    //objectList.push_back(sphere1);

    //CTriangle* triangle = new CTriangle ({3,3,-5},{-3,3,-10},{-3,-3,-8});
    //objectList.push_back(triangle);

/*    CTriangle* t1 = new CTriangle({-4.0f, 1.5f, 1.0f}, {-2.0f, 2.5f, -1.0f}, {-3.5f, 3.5f, 0.0f});
    t1->matAmbient = {0.8f, 0.1f, 0.1f};
    t1->matDiffuse = {0.0f, 0.0f, 0.0f};
    t1->matSpecular = {0.0f, 0.0f, 0.0f};
    objectList.push_back(t1);

    CTriangle* t2 = new CTriangle({-0.5f, 1.5f, -1.0f}, {0.5f, 1.5f, -1.0f}, {0.0f, 3.5f, -6.0f});
    t2->matAmbient = {0.1f, 0.8f, 0.1f};
    t2->matDiffuse = {0.0f, 0.0f, 0.0f};
    t2->matSpecular = {0.0f, 0.0f, 0.0f};
    objectList.push_back(t2);

    CTriangle* t3 = new CTriangle({2.0f, 2.0f, 0.0f}, {4.0f, 1.5f, -2.0f}, {2.5f, 3.5f, 2.0f});
    t3->matAmbient = {0.1f, 0.1f, 0.8f};
    t3->matDiffuse = {0.0f, 0.0f, 0.0f};
    t3->matSpecular = {0.0f, 0.0f, 0.0f};
    objectList.push_back(t3);

    CTriangle* t4 = new CTriangle({-4.5f, -1.0f, -3.0f}, {-3.5f, 0.5f, -4.0f}, {-4.2f, 1.0f, -1.0f});
    t4->matAmbient = {0.8f, 0.8f, 0.1f};
    t4->matDiffuse = {0.0f, 0.0f, 0.0f};
    t4->matSpecular = {0.0f, 0.0f, 0.0f};
    objectList.push_back(t4);

    CTriangle* t5 = new CTriangle({-1.0f, -1.0f, 1.0f}, {1.5f, -0.5f, -1.0f}, {0.0f, 1.0f, 0.0f});
    t5->matAmbient = {0.8f, 0.1f, 0.8f};
    t5->matDiffuse = {0.0f, 0.0f, 0.0f};
    t5->matSpecular = {0.0f, 0.0f, 0.0f};
    objectList.push_back(t5);

    CTriangle* t6 = new CTriangle({3.0f, -1.0f, -2.0f}, {4.5f, 1.0f, -4.0f}, {4.5f, -1.0f, -2.0f});
    t6->matAmbient = {0.1f, 0.8f, 0.8f};
    t6->matDiffuse = {0.0f, 0.0f, 0.0f};
    t6->matSpecular = {0.0f, 0.0f, 0.0f};
    objectList.push_back(t6);

    CTriangle* t7 = new CTriangle({-3.5f, -2.0f, 1.0f}, {-2.0f, -3.5f, -1.0f}, {-4.0f, -3.5f, -2.0f});
    t7->matAmbient = {0.9f, 0.5f, 0.1f};
    t7->matDiffuse = {0.0f, 0.0f, 0.0f};
    t7->matSpecular = {0.0f, 0.0f, 0.0f};
    objectList.push_back(t7);

    CTriangle* t8 = new CTriangle({-1.5f, -2.5f, -2.0f}, {1.5f, -2.0f, -3.0f}, {0.0f, -3.5f, -1.0f});
    t8->matAmbient = {0.2f, 0.2f, 0.2f};
    t8->matDiffuse = {0.0f, 0.0f, 0.0f};
    t8->matSpecular = {0.0f, 0.0f, 0.0f};
    objectList.push_back(t8);

    CTriangle* t9 = new CTriangle({2.5f, -2.0f, 2.0f}, {3.5f, -4.0f, -1.0f}, {3.0f, -1.5f, -4.0f});
    t9->matAmbient = {0.9f, 0.9f, 0.9f};
    t9->matDiffuse = {0.0f, 0.0f, 0.0f};
    t9->matSpecular = {0.0f, 0.0f, 0.0f};
    objectList.push_back(t9);

    CTriangle* t10 = new CTriangle({-7.0f, -2.0f, -15.0f}, {2.0f, 5.0f, -10.0f}, {-3.0f, 7.0f, -12.0f});
    t10->matAmbient = {0.7f, 0.7f, 0.7f};
    t10->matDiffuse = {0.0f, 0.0f, 0.0f};
    t10->matSpecular = {0.0f, 0.0f, 0.0f};
    objectList.push_back(t10);*/
}

