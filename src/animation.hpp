#ifndef __WFN_ENG_TEX_ANIMATION_HPP__
#define __WFN_ENG_TEX_ANIMATION_HPP__

#include <vector>

#include "texture.hpp"

namespace wfn_eng::tex {
    /**
     * A struct used to reduce memory use in `Animation`s by minimizing the
     * amount of information required to store sequences of frames.
     */
    struct FrameGuide {
        uint16_t textureIndex;
        uint16_t frameCount;
    };

    /**
     * Wrapper around several textures. Used to construct VkImages in the main
     * library.
     */
    struct Animation {
        std::vector<FrameGuide> frames;
        std::vector<Texture> textures;
    };
}

#endif
