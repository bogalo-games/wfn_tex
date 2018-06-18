#ifndef __WFN_ENG_TEX_TEXTURE_HPP__
#define __WFN_ENG_TEX_TEXTURE_HPP__

#include "stb_image.h"

namespace wfn_eng::tex {
    /**
     * A wrapper around stb_image.h to provide a more C++-style API to image
     * handling.
     */
    struct Texture {
        int width, height, channels;
        std::vector<stbi_uc> pixels;
    };
}

#endif
