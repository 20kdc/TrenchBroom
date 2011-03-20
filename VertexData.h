//
//  VertexData2.h
//  TrenchBroom
//
//  Created by Kristian Duske on 25.01.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

typedef enum {
    BM_KEEP,
    BM_DROP,
    BM_SPLIT
} EBrushMark;

@class MutableFace;
@class BoundingBox;
@class Ray3D;
@class PickingHitList;
@class Vector3f;

@interface VertexData : NSObject {
    @private
    NSMutableArray* vertices;
    NSMutableArray* edges;
    NSMutableArray* sides;
    NSMutableDictionary* faceToSide;
    NSMutableDictionary* centers;
    BoundingBox* bounds;
    BoundingBox* pickingBounds;
    Vector3f* center;
}

- (id)initWithFaces:(NSArray *)faces droppedFaces:(NSMutableArray **)droppedFaces;

- (BOOL)cutWithFace:(MutableFace *)face droppedFaces:(NSMutableArray **)droppedFaces;
- (NSArray *)verticesForFace:(MutableFace *)face;
- (NSArray *)vertices;
- (NSArray *)edges;
- (NSArray *)edgesForFace:(MutableFace *)face;
- (int)edgeCount;
- (BoundingBox *)bounds;
- (Vector3f *)center;

- (NSArray *)gridForFace:(MutableFace *)face gridSize:(int)gridSize;
- (Vector3f *)centerOfFace:(MutableFace *)face;

- (void)pickBrush:(Ray3D *)theRay hitList:(PickingHitList *)theHitList;
- (void)pickFace:(Ray3D *)theRay hitList:(PickingHitList *)theHitList;
- (void)pickEdge:(Ray3D *)theRay hitList:(PickingHitList *)theHitList;
- (void)pickVertex:(Ray3D *)theRay hitList:(PickingHitList *)theHitList;
- (BoundingBox *)pickingBounds;

@end
