#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../hittable.h"
#include "../vec3.h"

#define MIN_ORTHO_COMP 0.001

class triangle : public hittable {
    public:
        triangle(point3 _v1, point3 _v2, point3 _v3, shared_ptr<material> _material)
        : v1(_v1), v2(_v2), v3(_v3), mat(_material) 
        {
            vec3 v12 = v2 - v1;
            vec3 v13 = v3 - v1;
            n = cross(v12, v13);
        }

        triangle(point3 _v1, point3 _v2, point3 _v3, shared_ptr<material> _material, vec3 _n)
        : v1(_v1), v2(_v2), v3(_v3), mat(_material), n(_n) {}

        bool hit(const ray& r, interval ray_t, hit_record& rec) const override {


            //edge 0
            vec3 edge1 = v2 - v1;
            vec3 edge2 = v3 - v2;
            vec3 ray_cross_e2 = cross(r.direction(), edge2);

            float det = dot(edge1, ray_cross_e2);
            if (det > -MIN_ORTHO_COMP && det < MIN_ORTHO_COMP)
                return false;    // This ray is parallel to this triangle.

            float inv_det = 1.0 / det;
            vec3 s = r.origin() - v1;
            float u = inv_det * dot(s, ray_cross_e2);

            if (u < 0 || u > 1)
                return false;

            vec3 s_cross_e1 = cross(s, edge1);
            float v = inv_det * dot(r.direction(), s_cross_e1);

            if (v < 0 || u + v > 1)
                return false;

            // At this stage we can compute t to find out where the intersection point is on the line.
            float t = inv_det * dot(edge2, s_cross_e1);

            rec.t = t;
            rec.p = r.at(rec.t);
            rec.set_face_normal(r, -n);
            rec.mat = mat;

            return true; //ray hit triangle
        }
    
    private:
        point3 v1;
        point3 v2;
        point3 v3;
        shared_ptr<material> mat;
        vec3 n;
};

#endif