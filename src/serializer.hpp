// This file is part of Heimer.
// Copyright (C) 2018 Jussi Lind <jussi.lind@iki.fi>
//
// Heimer is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// Heimer is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Heimer. If not, see <http://www.gnu.org/licenses/>.

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "mind_map_data.hpp"

#include <QDomDocument>

namespace Serializer {
namespace DataKeywords {
namespace Design {

MindMapDataPtr fromXml(QDomDocument document);

QDomDocument toXml(MindMapData & mindMapData);

static constexpr auto DESIGN = "design";

static constexpr auto APPLICATION_VERSION = "version";

static constexpr auto COLOR = "color";

static constexpr auto CORNER_RADIUS = "corner-radius";

static constexpr auto EDGE_COLOR = "edge-color";

static constexpr auto EDGE_THICKNESS = "edge-width";

static constexpr auto GRAPH = "graph";

static constexpr auto IMAGE = "image";

static constexpr auto TEXT_SIZE = "text-size";

// Used for Design and Node
namespace Color {

static constexpr auto R = "r";

static constexpr auto G = "g";

static constexpr auto B = "b";
} // namespace Color

namespace Graph {

static constexpr auto NODE = "node";

namespace Node {

static constexpr auto COLOR = "color";

static constexpr auto IMAGE = "image";

static constexpr auto INDEX = "index";

static constexpr auto TEXT = "text";

static constexpr auto TEXT_COLOR = "text-color";

static constexpr auto X = "x";

static constexpr auto Y = "y";

static constexpr auto W = "w";

static constexpr auto H = "h";

namespace Image {

static constexpr auto REF = "ref";
} // namespace Image
} // namespace Node

static constexpr auto EDGE = "edge";

namespace Edge {

static constexpr auto INDEX0 = "index0";

static constexpr auto INDEX1 = "index1";

static constexpr auto ARROW_MODE = "arrow-mode";

static constexpr auto REVERSED = "reversed";

} // namespace Edge
} // namespace Graph

namespace Image {

static constexpr auto ID = "id";

} // namespace Image
} // namespace Design

} // namespace DataKeywords

MindMapDataPtr fromXml(QDomDocument document);

QDomDocument toXml(MindMapData & mindMapData);

} // namespace Serializer

#endif // SERIALIZER_HPP
