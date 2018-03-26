// This file is part of Dementia.
// Copyright (C) 2018 Jussi Lind <jussi.lind@iki.fi>
//
// Dementia is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// Dementia is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Dementia. If not, see <http://www.gnu.org/licenses/>.

#ifndef NODEBASE_HPP
#define NODEBASE_HPP

#include <QSizeF>
#include <QString>
#include <QPointF>

#include <memory>
#include <vector>

//! Base class for freely placeable target nodes in the editor.
class NodeBase
{
public:

    using NodeBasePtr = std::shared_ptr<NodeBase>;

    NodeBase();

    NodeBase(NodeBase & other) = delete;

    NodeBase & operator= (NodeBase & other) = delete;

    virtual ~NodeBase();

    virtual QPointF location() const;

    virtual void setLocation(QPointF newLocation);

    virtual QSize size() const;

    virtual void setSize(QSize size);

    virtual int index() const;

    virtual void setIndex(int index);

    virtual QString text() const;

    virtual void setText(const QString & text);

private:

    QPointF m_location;

    QSize m_size;

    QString m_text;

    int m_index = -1;
};

using NodeBasePtr = std::shared_ptr<NodeBase>;

#endif // NODEBASE_HPP