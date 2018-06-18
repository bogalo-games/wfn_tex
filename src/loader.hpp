#ifndef __WFN_ENG_TEX_LOADER_HPP__
#define __WFN_ENG_TEX_LOADER_HPP__

#include <fstream>
#include <string>

#include "animation.hpp"
#include "texture.hpp"

namespace wfn_eng::tex::loader {
    /**
     * Fills a Texture at the reference provided with the data from an input
     * stream.
     */
    void fillTexture(Texture& texture, std::istream& input);

    /**
     * Fills the Texture at the reference provided with the information located
     * at the path provided.
     */
    void fillTexture(Texture& texture, std::string path);

    /**
     * Fills the Animation at the reference provided with the information
     * located at the path provided.
     *
     * Refer to the README.md for file spec.
     */
    void fillAnimation(Animation& animation, std::string path);
}

#endif
