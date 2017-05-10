﻿#pragma once

class fcIGifContext
{
public:
    virtual void release() = 0;

    virtual void addOutputStream(fcStream *s) = 0;
    virtual bool addFrameTexture(void *tex, fcPixelFormat fmt, fcTime timestamp = -1) = 0;
    virtual bool addFramePixels(const void *pixels, fcPixelFormat fmt, fcTime timestamp = -1) = 0;
    virtual void forceKeyframe() = 0;

protected:
    virtual ~fcIGifContext() {}
};

fcIGifContext* fcGifCreateContextImpl(const fcGifConfig &conf, fcIGraphicsDevice *dev);
