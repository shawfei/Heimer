// This file is part of Heimer.
// Copyright (C) 2020 Jussi Lind <jussi.lind@iki.fi>
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

#include "recent_files_menu.hpp"
#include "recent_files_manager.hpp"

#include <functional>

RecentFilesMenu::RecentFilesMenu(QWidget * parent)
  : QMenu(parent)
{
    connect(this, &QMenu::aboutToShow, [this]() {
        for (auto && action : actions()) {
            removeAction(action);
        }
        // clang-format off
        for (auto && filePath : RecentFilesManager::instance().getRecentFiles()) {
            const auto action = addAction(filePath);
            const auto handler = std::bind([this](QString filePath) {
                RecentFilesManager::instance().setSelectedFile(filePath);
                this->fileSelected(filePath);
            }, action->text());
            connect(action, &QAction::triggered, handler);
        }
        // clang-format on
    });
}
