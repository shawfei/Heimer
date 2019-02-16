// This file is part of Heimer.
// Copyright (C) 2019 Jussi Lind <jussi.lind@iki.fi>
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

#ifndef LAYOUT_OPTIMIZER_HPP
#define LAYOUT_OPTIMIZER_HPP

#include <cmath>
#include <memory>
#include <vector>

#include "mind_map_data.hpp"
#include "node.hpp"

class Graph;

class LayoutOptimizer
{
public:

    LayoutOptimizer(MindMapDataPtr mindMapData);

    void initialize(double aspectRatio, double minEdgeLength);

    void optimize();

    void extract();

private:

    double calculateCost() const;

    struct Cell;

    struct Row;

    struct Change
    {
        enum class Type
        {
            Move,
            Swap
        };

        Type type;

        Cell * sourceCell = nullptr;

        Cell * targetCell = nullptr;

        Row * sourceRow = nullptr;

        Row * targetRow = nullptr;

        size_t sourceIndex = 0;

        size_t targetIndex = 0;
    };

    void doChange(const LayoutOptimizer::Change & change);

    void undoChange(LayoutOptimizer::Change change);

    Change planChange() const;

    MindMapDataPtr m_mindMapData;

    struct Rect
    {
        Rect() {}

        ~Rect() {}

        int x = 0;

        int y = 0;

        int w = 0;

        int h = 0;
    };

    struct Cell
    {
        Cell() {}

        ~Cell() {}

        inline double distance(Cell & other)
        {
            const double dx = std::abs(rect.x + rect.w / 2 - other.rect.x - other.rect.w / 2);
            const double dy = std::abs(rect.y + rect.h / 2 - other.rect.y - other.rect.h / 2);
            return dx + dy;
        }

        inline double getConnectionCost(const std::vector<Cell *> & connections)
        {
            double cost = 0;
            for (auto && cell : connections)
            {
                cost += distance(*cell);
            }
            return cost;
        }

        inline double getOutCost()
        {
            return getConnectionCost(out);
        }

        inline double getCompoundCost()
        {
            return getConnectionCost(in) + getConnectionCost(out);
        }

        inline void popRect()
        {
            rect = stash;
        }

        inline void pushRect()
        {
            stash = rect;
        }

        std::vector<Cell *> in;

        std::vector<Cell *> out;

        NodeBasePtr node;

        Rect rect;

        Rect stash;
    };

    struct Row
    {
        Row() {}

        ~Row()
        {
            for (auto cell : cells)
            {
                delete cell;
            }
        }

        std::vector<Cell *> cells;

        Rect rect;
    };

    struct Layout
    {
        Layout() {}

        ~Layout()
        {
            for (auto row : rows)
            {
                delete row;
            }
        }

        double minEdgeLength = 0;

        std::vector<Cell *> all;

        std::vector<Row *> rows;
    };

    std::unique_ptr<Layout> m_layout;
};

#endif // LAYOUT_OPTIMIZER_HPP
