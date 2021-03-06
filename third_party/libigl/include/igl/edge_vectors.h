// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2020 Oded Stein <oded.stein@columbia.edu>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#ifndef IGL_EDGE_VECTORS_H
#define IGL_EDGE_VECTORS_H
#include "igl_inline.h"

#include <Eigen/Dense>
namespace igl
{
// Computes the normalized edge vectors for edges in a triangle mesh
//
// Input:
// V, F: triangle mesh
// E, oE: mapping from halfedges to edges and orientation as generated by
//    orient_halfedges
//
// Output:
// vec: normalized edge vectors for each unique edge in E, according to order
//      of E.
template<typename DerivedV,typename DerivedF,typename DerivedE,
typename DerivedoE, typename Derivedvec>
IGL_INLINE void edge_vectors(
                             const Eigen::MatrixBase<DerivedV> &V,
                             const Eigen::MatrixBase<DerivedF> &F,
                             const Eigen::MatrixBase<DerivedE> &E,
                             const Eigen::MatrixBase<DerivedoE> &oE,
                             Eigen::PlainObjectBase<Derivedvec> &vec);


// Computes the normalized edge vectors for edges in a triangle mesh
//
// Input:
// V, F: triangle mesh
// E, oE: mapping from halfedges to edges and orientation as generated by
//    orient_halfedges
// template parameter computePerpendicular: whether to compute
//                                          vecPerpendicular or not.
//
// Output:
// vecParallel: normalized edge vectors for each unique edge in E, according
//              to order of E.
// vecPerpendicular: tangent unit perpendicular vector to each edge, according
//                   to orientation in oE, corresponds to each vector in
//                   vecParallel rotated by pi/2 around an edge-based normal.
//
template<bool computePerpendicular=true,
typename DerivedV,typename DerivedF,typename DerivedE,
typename DerivedoE, typename DerivedvecParallel,
typename DerivedvecPerpendicular>
IGL_INLINE void edge_vectors(
                             const Eigen::MatrixBase<DerivedV> &V,
                             const Eigen::MatrixBase<DerivedF> &F,
                             const Eigen::MatrixBase<DerivedE> &E,
                             const Eigen::MatrixBase<DerivedoE> &oE,
                             Eigen::PlainObjectBase<DerivedvecParallel> &vecParallel,
                             Eigen::PlainObjectBase<DerivedvecPerpendicular> &vecPerpendicular);
}

#ifndef IGL_STATIC_LIBRARY
#  include "edge_vectors.cpp"
#endif

#endif
