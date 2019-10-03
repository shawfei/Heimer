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

#ifndef IMAGE_MANAGER_HPP
#define IMAGE_MANAGER_HPP

#include <QObject>

#include <map>

#include "image.hpp"

class Node;

class ImageManager : public QObject
{
    Q_OBJECT

public:
    ImageManager();

    int addImage(const Image & image);

    std::pair<Image, bool> getImage(int id);

    void handleImageRequest(int id, Node & node);

    using ImageVector = std::vector<Image>;
    ImageVector images() const;

private:
    std::map<int, Image> m_images;

    int m_count = 0;
};

#endif // IMAGE_MANAGER_HPP
