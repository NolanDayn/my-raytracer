#include "rtweekend.h"

#include "camera.h"
#include "color.h"
#include "hittable.h"
#include "hittable_list.h"
#include "shapes/sphere.h"
#include "shapes/triangle.h"

#include <iostream>

int main() {

    // World
    hittable_list world;
    
    auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5)); 
    world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100, ground_material));
    
    auto material2 = make_shared<lambertian>(color(0.4, 0.2, 0.1));
    world.add(make_shared<triangle>(point3(1,-1,0), point3(1.5,-1,3), point3(2,-1,0), material2));

    // Camera
    camera cam;
    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 600;
    cam.samples_per_pixel = 25;
    cam.max_depth         = 20;
    cam.vfov              = 20;
    cam.lookfrom          = point3(13,2,3);
    cam.lookat            = point3(0,0,0);
    cam.vup               = point3(0,1,0);
    cam.defocus_angle     = 0.00;
    cam.focus_dist        = 10.0;
    
    cam.render(world);
}
