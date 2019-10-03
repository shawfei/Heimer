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

#ifndef MAIN_CONTEXT_MENU_HPP
#define MAIN_CONTEXT_MENU_HPP

#include <map>
#include <vector>

#include <QMenu>

#include "state_machine.hpp"

class CopyPaste;
class Grid;
class Node;
class Mediator;

class MainContextMenu : public QMenu
{
    Q_OBJECT

public:
    enum class Mode
    {
        All,
        Background,
        Node
    };

    MainContextMenu(QWidget * parent, Mediator & mediator, Grid & grid, CopyPaste & copyPaste);

    void setMode(const Mode & mode);

signals:

    void actionTriggered(StateMachine::Action action, Node * node = nullptr);

    void nodeColorActionTriggered();

    void nodeTextColorActionTriggered();

    void newNodeRequested(QPointF position);

private:
    QAction * m_copyNodeAction;

    QAction * m_pasteNodeAction;

    Node * m_selectedNode = nullptr;

    std::map<Mode, std::vector<QAction *>> m_mainContextMenuActions;

    Mediator & m_mediator;

    CopyPaste & m_copyPaste;
};

#endif // MAIN_CONTEXT_MENU_HPP
