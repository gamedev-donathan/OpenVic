#pragma once

#include <godot_cpp/classes/image_texture.hpp>

#include <openvic-simulation/utility/Getters.hpp>

namespace OpenVic {
	class GFXButtonStateTexture : public godot::ImageTexture {
		GDCLASS(GFXButtonStateTexture, godot::ImageTexture)

	public:
		enum ButtonState {
			HOVER,
			PRESSED,
			DISABLED
		};

	private:
		ButtonState PROPERTY(button_state);
		godot::Ref<godot::Image> state_image;

	protected:
		static void _bind_methods();

	public:
		GFXButtonStateTexture();

		/* Create a GFXButtonStateTexture using the specified godot::Image. Returns nullptr if generate_state_image fails. */
		static godot::Ref<GFXButtonStateTexture> make_gfx_button_state_texture(
			ButtonState button_state, godot::Ref<godot::Image> const& source_image = nullptr
		);

		/* Set the ButtonState to be generated by this class (calling this does not trigger state image generation). */
		void set_button_state(ButtonState new_button_state);

		/* Generate a modified version of source_image and update the underlying godot::ImageTexture to use it. */
		godot::Error generate_state_image(godot::Ref<godot::Image> const& source_image);

		static godot::StringName const& get_generate_state_image_func_name();

		static godot::StringName const& button_state_to_theme_name(ButtonState button_state);
		godot::StringName const& get_button_state_theme() const;
	};
}

VARIANT_ENUM_CAST(OpenVic::GFXButtonStateTexture::ButtonState);
