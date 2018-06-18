#ifndef __WFN_ENG_TEX_LOADER_HPP__
#define __WFN_ENG_TEX_LOADER_HPP__

#include <string>

#include "animation.hpp"
#include "texture.hpp"

namespace wfn_eng::tex::loader {
    /**
     * Fills the Texture at the reference provided with the information located
     * at the path provided.
     */
    void fillTexture(Texture& texture, std::string path);

    /**
     * Loads a Texture from a location on disk.
     *
     * Note that because this copies the texture in returning from the function,
     * this will incur performance hits that fillTexture does not.
     */
    Texture loadTexture(std::string path);

    /**
     * Fills the Animation at the reference provided with the information
     * located at the path provided.
     *
     * Refer to the README.md for file spec.
     */
    void fillAnimation(Animation& animation, std::string path);

    /**
     * Loads an Animation from a location on disk.
     *
     * Same warning as loadTexture for performance hit.
     */
    Animation loadAnimation(std::string path);
}

#endif
