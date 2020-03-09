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

#include <QTest>

class SerializerTest : public QObject
{
    Q_OBJECT

public:
    SerializerTest();

private slots:

    void testEmptyDesign();

    void testBackgroundColor();

    void testCornerRadius();

    void testEdgeColor();

    void testEdgeWidth();

    void testNotUsedImages();

    void testNodeDeletion();

    void testSingleEdge();

    void testSingleNode();

    void testTextSize();

    void testUsedImages();
};
