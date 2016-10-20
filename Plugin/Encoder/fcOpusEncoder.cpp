#include "pch.h"
#include "fcFoundation.h"
#include "fcVorbisEncoder.h"

#include "opus/opus.h"


class fcOpusEncoder : public fcIVorbisEncoder
{
public:
    fcOpusEncoder(const fcOpusEncoderConfig& conf);
    ~fcOpusEncoder() override;
    void release() override;
    const char* getMatroskaCodecID() const override;
    const Buffer& getCodecPrivate() const override;

    bool encode(fcVorbisFrame& dst, const float *samples, size_t num_samples) override;

private:
    fcOpusEncoderConfig m_conf;
    Buffer m_codec_private;
};


fcIVorbisEncoder* fcCreateOpusEncoder(const fcOpusEncoderConfig& conf)
{
    return new fcOpusEncoder(conf);
}


fcOpusEncoder::fcOpusEncoder(const fcOpusEncoderConfig& conf)
    : m_conf(conf)
{
}

fcOpusEncoder::~fcOpusEncoder()
{
}

void fcOpusEncoder::release()
{
    delete this;
}

const char* fcOpusEncoder::getMatroskaCodecID() const
{
    return "A_OPUS";
}

const Buffer& fcOpusEncoder::getCodecPrivate() const
{
    return m_codec_private;
}

bool fcOpusEncoder::encode(fcVorbisFrame& dst, const float *samples, size_t num_samples)
{
    return false;
}

