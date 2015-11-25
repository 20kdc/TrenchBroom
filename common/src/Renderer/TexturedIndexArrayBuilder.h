/*
 Copyright (C) 2010-2014 Kristian Duske
 
 This file is part of TrenchBroom.
 
 TrenchBroom is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 TrenchBroom is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with TrenchBroom. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TexturedIndexArrayBuilder_h
#define TexturedIndexArrayBuilder_h

#include "Renderer/TexturedIndexArray.h"
#include "Renderer/VertexListBuilder.h"

namespace TrenchBroom {
    namespace Assets {
        class Texture;
    }
    
    namespace Renderer {
        template <typename VertexSpec>
        class TexturedIndexArrayBuilder {
        public:
            typedef typename VertexSpec::Vertex Vertex;
            typedef typename Vertex::List VertexList;
            typedef Assets::Texture Texture;
        private:
            typedef typename VertexListBuilder<VertexSpec>::IndexData IndexData;
        private:
            VertexListBuilder<VertexSpec> m_vertexListBuilder;
            TexturedIndexArray m_indexArray;
        public:
            TexturedIndexArrayBuilder(const size_t vertexCount, const TexturedIndexArray::Size& indexArraySize) :
            m_vertexListBuilder(vertexCount),
            m_indexArray(indexArraySize) {}
            
            const VertexList& vertices() const {
                return m_vertexListBuilder.vertices();
            }
            
            VertexList& vertices() {
                return m_vertexListBuilder.vertices();
            }
            
            const TexturedIndexArray& indexArray() const {
                return m_indexArray;
            }
            
            TexturedIndexArray& indexArray() {
                return m_indexArray;
            }
            
            void addPoint(const Texture* texture, const Vertex& v) {
                add(texture, IndexArray::PT_Points, m_vertexListBuilder.addPoint(v));
            }
            
            void addPoints(const Texture* texture, const VertexList& vertices) {
                add(texture, IndexArray::PT_Points, m_vertexListBuilder.addPoints(vertices));
            }
            
            void addLine(const Texture* texture, const Vertex& v1, const Vertex& v2) {
                add(texture, IndexArray::PT_Lines, m_vertexListBuilder.addLine(v1, v2));
            }
            
            void addLines(const Texture* texture, const VertexList& vertices) {
                add(texture, IndexArray::PT_Lines, m_vertexListBuilder.addLines(vertices));
            }
            
            void addLineStrip(const Texture* texture, const VertexList& vertices) {
                add(texture, IndexArray::PT_LineStrips, m_vertexListBuilder.addLineStrip(vertices));
            }
            
            void addLineLoop(const Texture* texture, const VertexList& vertices) {
                add(texture, IndexArray::PT_LineLoops, m_vertexListBuilder.addLineLoop(vertices));
            }
            
            void addTriangle(const Texture* texture, const Vertex& v1, const Vertex& v2, const Vertex& v3) {
                add(texture, IndexArray::PT_Triangles, m_vertexListBuilder.addTriangle(v1, v2, v3));
            }
            
            void addTriangles(const Texture* texture, const VertexList& vertices) {
                add(texture, IndexArray::PT_Triangles, m_vertexListBuilder.addTriangles(vertices));
            }
            
            void addTriangleFan(const Texture* texture, const VertexList& vertices) {
                add(texture, IndexArray::PT_TriangleFans, m_vertexListBuilder.addTriangleFan(vertices));
            }
            
            void addTriangleStrip(const Texture* texture, const VertexList& vertices) {
                add(texture, IndexArray::PT_TriangleStrips, m_vertexListBuilder.addTriangleStrip(vertices));
            }
            
            void addQuad(const Texture* texture, const Vertex& v1, const Vertex& v2, const Vertex& v3, const Vertex& v4) {
                add(texture, IndexArray::PT_Quads, m_vertexListBuilder.addQuad(v1, v2, v3, v4));
            }
            
            void addQuads(const Texture* texture, const VertexList& vertices) {
                add(texture, IndexArray::PT_Quads, m_vertexListBuilder.addQuads(vertices));
            }
            
            void addQuadStrip(const Texture* texture, const VertexList& vertices) {
                add(texture, IndexArray::PT_QuadStrips, m_vertexListBuilder.addQuadStrip(vertices));
            }
            
            void addPolygon(const Texture* texture, const VertexList& vertices) {
                add(texture, IndexArray::PT_Polygons, m_vertexListBuilder.addPolygon(vertices));
            }
        private:
            void add(const Texture* texture, const IndexArray::PrimType primType, const IndexData& data) {
                m_indexArray.add(texture, primType, data.index, data.count);
            }
        };
    }
}

#endif /* TexturedIndexArrayBuilder_h */
