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

#include "image_manager.hpp"
#include "contrib/SimpleLogger/src/simple_logger.hpp"
#include "node.hpp"

ImageManager::ImageManager()
{
}

int ImageManager::addImage(const Image & image)
{
    const auto id = m_count++;
    m_images[id] = image;
    m_images[id].id = id;

    juzzlin::L().info() << "Adding new image, path=" << image.path << ", id=" << id;

    return id;
}

std::pair<Image, bool> ImageManager::getImage(int id)
{
    if (m_images.count(id)) {
        return { m_images[id], true };
    }
    return { {}, false };
}

void ImageManager::handleImageRequest(int id, Node & node)
{
    const auto && imagePair = getImage(id);
    if (imagePair.second) {
        juzzlin::L().info() << "Applying image id=" << id << " to node " << node.index();
        node.applyImage(imagePair.first);
    } else {
        juzzlin::L().warning() << "Cannot find image with id=" << id;
    }
}

ImageManager::ImageVector ImageManager::images() const
{
    ImageVector images;
    for (auto && image : m_images) {
        images.push_back(image.second);
    }
    return images;
}
