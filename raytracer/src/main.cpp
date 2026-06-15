
#include <iostream>


#include "rt.h"

extern void draw_robot();
extern void draw_triangles();

///
int main (int argc, char * const argv[]) {

    //draw_triangles();
    //draw_robot();
    //return 0;

    std::cout << "ray tracing ... \n";

    CScene scene;
    scene.create(); // defines sample scene parameters
    if(scene.cam.width == 0) {
        std::cout << "WARNING: scene not defined" << std::endl;
        return -1;
    }

    CRayTrace rt;
    CRay ray, ray1;
    COutput results;
    
    /// computes primary ray matrix
    glm::mat3 ray_matrix;
    CRayTrace::compPrimaryRayMatrix(scene.cam, ray_matrix);
    //std::cout << "Camera projection matrix:" << std::endl;
    //PRINT_MAT3(ray_matrix);

    CSphere sphere1_t ({0.0f,0.0f,0.0f},5.0f);
    ray1.pos = {0.0f,0.0f,10.0f};
    ray1.dir = {0.3f,0.3f,-1.0f};

    //std::cout << "T = " << sphere1_t.intersect(ray1);

    /// computes ray direction for sample pixel positions
    /*ray.pos = scene.cam.eyep;
    float fx = (float)scene.cam.width/2 - 1 + 0.5f;
    float fy = (float)scene.cam.height/2 - 1 + 0.5f;
    glm::vec3 position(fx,fy,1);
    ray.dir = glm::normalize(ray_matrix * position);
    PRINT_VEC3("dir = ", ray.dir);*/

    /*ray.pos = scene.cam.eyep;
    float fx = 0.5f;
    float fy = 0.5f;
    glm::vec3 position(fx,fy,1);
    ray.dir = glm::normalize(ray_matrix * position);
    PRINT_VEC3("dir = ", ray.dir);*/

    /*ray.pos = scene.cam.eyep;
    float fx = (float)scene.cam.width/2 - 1 + 0.5f;
    float fy = 0.5f;
    glm::vec3 position(fx,fy,1);
    ray.dir = glm::normalize(ray_matrix * position);
    PRINT_VEC3("dir = ", ray.dir);*/

    /*ray.pos = scene.cam.eyep;
    float fx = 0.5f;
    float fy = (float)scene.cam.height/2 - 1 + 0.5f;
    glm::vec3 position(fx,fy,1);
    ray.dir = glm::normalize(ray_matrix * position);
    PRINT_VEC3("dir = ", ray.dir);*/

    /*ray.pos = scene.cam.eyep;
    float fx = (float)scene.cam.width - 1 + 0.5f;
    float fy = (float)scene.cam.height - 1 + 0.5f;
    glm::vec3 position(fx,fy,1);
    ray.dir = glm::normalize(ray_matrix * position);
    PRINT_VEC3("dir = ", ray.dir);*/


    /// creates raster image object
    CImage image(scene.cam.width, scene.cam.height);

    /// main loop
    for(int j = 0; j < scene.cam.height; j++){
        for(int i = 0; i < scene.cam.width; i++){
            /// position of the image point
            float fx = (float)i + 0.5f;
            float fy = (float)j + 0.5f;
            ray.pos = scene.cam.eyep;
            glm::vec3 position(fx,fy,1);
            ray.dir = glm::normalize(ray_matrix * position);
            //glm::vec3 rgb(0.0f, 0.0f, 0.0f);
            //rgb.z = (ray.dir.z + 1.0f)/2.0f;
            //image.setPixel(i,j,rgb);

            /// primary ray
            /// ...

            /// background color
            results.col = {0,0,0};
            /// secondary ray counter
            results.tree = 0;
            /// ray energy
            results.energy = 1.0f;

            /// rendering
            rt.rayTrace(scene, ray, results);

            /// handles pixel over-saturation
            if(results.col.x > 1 || results.col.y > 1 || results.col.z > 1) {
                results.col = {1,1,1};
            }

            /// writes pixel to output image
            image.setPixel(i, j, results.col);
        }
    }

    /// writes image to disk file with gamma correction
    image.save("shadow.png", false);

    cv::imshow("shadow", image.getImage());
    //cv::waitKey();

    return 0;
}


/// Draws two trianges
void draw_triangles() {

    CImage img(1000, 1000);
    
    glm::vec3 color1(0.9,0.1,0.1); // red
    glm::vec3 color2(0.1,0.9,0.1); // green
    
    // draw circle
    glm::vec3 pp(0.0,0.0,1.0);
    float radius = 0.1f;
    img.drawCircle(pp, radius, color1);
    
    // triangle vertices
    glm::vec3 pp0(0.4, 0.3, 1);
    glm::vec3 pp1(-0.4, 0.3, 1);
    glm::vec3 pp2(0.4, -0.3, 1);
    
    // draws triangle in 2D
    img.drawLine(pp0, pp1, color1);
    img.drawLine(pp1, pp2, color1);
    img.drawLine(pp2, pp0, color1);
    
    // translation
    float tX = 0.2f; // OX translation
    float tY = 0.1f; // OY translation
    glm::mat3x3 mTrans {{1,0,0}, {0,1,0}, {tX,tY,1}}; // translation matrix
    PRINT_MAT3(mTrans);

    // translation of vertices
    pp0 = mTrans * pp0;
    pp1 = mTrans * pp1;
    pp2 = mTrans * pp2;

    // draws triangle after translation
    img.drawLine(pp0, pp1, color2);
    img.drawLine(pp1, pp2, color2);
    img.drawLine(pp2, pp0, color2);

    img.save("robot.png");
    cv::imshow("ROBOT", img.getImage());
    cv::waitKey();

}

/// Draws robot.
void draw_robot() {
    CImage img(1000, 1000);

    glm::vec3 orange(1.0, 0.729, 0.0);

    // draw circle
    glm::vec3 pp(0.0, 0.8, 1.0);
    float radius = 0.089f;
    img.drawCircle(pp, radius, orange);

    // draw tors
    glm::vec3 pt0(0.2, 0.68, 1);
    glm::vec3 pt1(-0.2, 0.68, 1);
    glm::vec3 pt2(0.2, 0.2, 1);
    glm::vec3 pt3(-0.2, 0.2, 1);

    img.drawLine(pt0, pt1, orange);
    img.drawLine(pt1, pt3, orange);
    img.drawLine(pt3, pt2, orange);
    img.drawLine(pt2, pt0, orange);

    // draw first hand
    glm::vec3 phl0(0.54, 0.68, 1);
    glm::vec3 phl1(0.24, 0.68, 1);
    glm::vec3 phl2(0.54, 0.58, 1);
    glm::vec3 phl3(0.24, 0.58, 1);

    img.drawLine(phl0, phl1, orange);
    img.drawLine(phl1, phl3, orange);
    img.drawLine(phl3, phl2, orange);
    img.drawLine(phl2, phl0, orange);

    // draw first leg
    glm::vec3 pll0(0.3, 0.16, 1);
    glm::vec3 pll1(0.4, -0.28, 1);
    glm::vec3 pll2(0.2, 0.14, 1);
    glm::vec3 pll3(0.3, -0.3, 1);

    img.drawLine(pll0, pll1, orange);
    img.drawLine(pll1, pll3, orange);
    img.drawLine(pll3, pll2, orange);
    img.drawLine(pll2, pll0, orange);

    // reflection matrix (symmetry across Y-axis)
    glm::mat3x3 mMirror {{-1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    PRINT_MAT3(mMirror);

    // second hand transformation
    phl0 = mMirror * phl0;
    phl1 = mMirror * phl1;
    phl2 = mMirror * phl2;
    phl3 = mMirror * phl3;

    // draws second hand after transformation
    img.drawLine(phl0, phl1, orange);
    img.drawLine(phl1, phl3, orange);
    img.drawLine(phl3, phl2, orange);
    img.drawLine(phl2, phl0, orange);

    // second leg transformation
    pll0 = mMirror * pll0;
    pll1 = mMirror * pll1;
    pll2 = mMirror * pll2;
    pll3 = mMirror * pll3;

    // draws second leg after transformation
    img.drawLine(pll0, pll1, orange);
    img.drawLine(pll1, pll3, orange);
    img.drawLine(pll3, pll2, orange);
    img.drawLine(pll2, pll0, orange);

    img.save("robot.png");
    cv::imshow("ROBOT", img.getImage());
    cv::waitKey();
}