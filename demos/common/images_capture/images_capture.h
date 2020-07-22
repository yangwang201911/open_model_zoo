// Copyright (C) 2020 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include <memory>
#include <string>

#include <opencv2/core/mat.hpp>
#include <opencv2/videoio.hpp>

class ImagesCapture {
public:
    const bool loop;

    ImagesCapture(bool loop) : loop{loop} {}
    virtual double fps() const = 0;
    virtual size_t lastImgId() const = 0;
    virtual cv::Mat read() = 0;
    virtual ~ImagesCapture() = default;
};

std::unique_ptr<ImagesCapture> openImagesCapture(const std::string &input,
        bool loop, size_t posFrames=0,  // Non camera options
        size_t readLengthLimit=std::numeric_limits<size_t>::max(),  // general option
        // Camera options:
        double buffersize=1, double frameWidth=1280, double frameHeight=720, double autofocus=true,
        double fourcc=cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));
