#include "loader.hpp"

#include <cstdlib>
#include <cstring>
#include <fstream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace wfn_eng::tex::loader {
    /**
     * Fills a Texture at the reference provided with the data from an input
     * stream.
     */
    void fillTexture(Texture& texture, std::istream& input) {
        stbi_io_callbacks callbacks {
            .eof = [](void *pInput) {
                auto& input = *reinterpret_cast<std::istream *>(pInput);
                return static_cast<int>(input.eof());
            },

            .read = [](void *pInput, char *data, int size) {
                // TODO: Read thing
                return 0;
            },

            .skip = [](void *pInput, int size) {
                // TODO: Skip thing
            }
        };

        stbi_uc *pixels = stbi_load_from_callbacks(
            &callbacks,
            &input,
            &texture.width,
            &texture.height,
            &texture.channels,
            STBI_rgb_alpha
        );

        size_t pixelCount = texture.width * texture.height * texture.channels;
        texture.pixels.resize(pixelCount);
        memcpy(texture.pixels.data(), pixels, pixelCount);
    }

    /**
     * Fills the Texture at the reference provided with the information located
     * at the path provided.
     */
    void fillTexture(Texture& texture, std::string path) {
        std::ifstream file(path);
        fillTexture(texture, file);
    }

    /**
     * Fills the Animation at the reference provided with the information
     * located at the path provided.
     *
     * Refer to the README.md for file spec.
     */
    void fillAnimation(Animation& animation, std::string path) {
        std::ifstream file(path);

        char header[4];
        file.read(header, 2);

        if (strcmp(header, "ANIM") != 0) {
            // TODO: Fail and return
        }

        uint32_t frameGuideCount;
        uint32_t textureCount;

        // Reading in frameguide and texture counts
        file.read(reinterpret_cast<char *>(&frameGuideCount), 4);
        file.read(reinterpret_cast<char *>(&textureCount), 4);

        animation.frames.resize(frameGuideCount);
        animation.textures.resize(textureCount);

        // Reading in frameguides
        for (size_t i; i < frameGuideCount; i++) {
            auto& frame = animation.frames[i];
            file.read(reinterpret_cast<char *>(&frame.textureIndex), 2);
            file.read(reinterpret_cast<char *>(&frame.frameCount), 2);
        }

        // Reading in textures.
        for (size_t i; i < textureCount; i++) {
            // TODO: Read in? how do I do this with the current texture API?
        }
    }
}
