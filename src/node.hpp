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

#ifndef NODE_HPP
#define NODE_HPP

#include <QGraphicsItem>
#include <QImage>
#include <QObject>
#include <QTimer>

#include <map>
#include <vector>

#include "edge.hpp"
#include "edge_point.hpp"
#include "node_base.hpp"

class Image;
class NodeHandle;
class QGraphicsTextItem;
class TextEdit;

//! Freely placeable target node.
class Node : public QObject, public QGraphicsItem, public NodeBase
{
    Q_OBJECT

    Q_INTERFACES(QGraphicsItem)

public:
    //! Constructor.
    Node();

    //! Copy constructor.
    Node(const Node & other);

    ~Node() override;

    void addGraphicsEdge(Edge & edge);

    void removeGraphicsEdge(Edge & edge);

    void adjustSize();

    QRectF boundingRect() const override;

    using NodePtr = std::shared_ptr<Node>;
    EdgePtr createAndAddGraphicsEdge(NodePtr targetNode);

    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = nullptr) override;

    //! Sets the Node and QGraphicsItem locations.
    void setLocation(QPointF newLocation) override;

    void hoverEnterEvent(QGraphicsSceneHoverEvent * event) override;

    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event) override;

    void hoverMoveEvent(QGraphicsSceneHoverEvent * event) override;

    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;

    static std::pair<EdgePoint, EdgePoint> getNearestEdgePoints(const Node & node1, const Node & node2);

    void setHandlesVisible(bool visible, bool all = true);

    QString text() const override;

    void setColor(const QColor & color) override;

    void setCornerRadius(int value) override;

    void setTextInputActive();

    void setText(const QString & text) override;

    void setTextColor(const QColor & color) override;

    void setTextSize(int textSize) override;

    void setSelected(bool selected) override;

    void setImageRef(size_t imageRef) override;

    void applyImage(const Image & image);

signals:

    void undoPointRequested();

    void imageRequested(size_t imageRef, Node & node);

private:
    void checkHandleVisibility(QPointF pos);

    void createEdgePoints();

    void createHandles();

    QRectF expandedTextEditRect() const;

    NodeHandle * hitsHandle(QPointF pos);

    void initTextField();

    void updateEdgeLines();

    std::vector<NodeHandle *> m_handles;

    std::vector<Edge *> m_graphicsEdges;

    std::vector<EdgePoint> m_edgePoints;

    TextEdit * m_textEdit;

    QTimer m_handleVisibilityTimer;

    QPointF m_currentMousePos;

    bool m_mouseIn = false;

    QPixmap m_pixmap;
};

using NodePtr = std::shared_ptr<Node>;

#endif // NODE_HPP
