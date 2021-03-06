#pragma  once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "../system/sfml/Window.hpp"
#include "core/events/event.hpp"
#include <chrono>
struct FrameBuffer;
class RenderWindow : public sf::Window
{
public:
	//-----------------------------------------------------------------------------
	//  Name : RenderWindow ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	RenderWindow();

	//-----------------------------------------------------------------------------
	//  Name : RenderWindow ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	RenderWindow(sf::VideoMode mode, const std::string& title, std::uint32_t style = sf::Style::Default);

	//-----------------------------------------------------------------------------
	//  Name : ~RenderWindow (virtual )
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	virtual ~RenderWindow();

	/// event triggered when window is resized.
	event<void(RenderWindow&, const uSize&)> on_resized;
	/// event triggered when window is closed.
	event<void(RenderWindow&)> on_closed;

	//-----------------------------------------------------------------------------
	//  Name : get_surface ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	inline std::shared_ptr<FrameBuffer> get_surface() { return _surface; }

	//-----------------------------------------------------------------------------
	//  Name : get_surface ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	inline std::shared_ptr<FrameBuffer> get_surface() const { return _surface; }

	//-----------------------------------------------------------------------------
	//  Name : prepare_surface (virtual )
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	virtual void prepare_surface();

	//-----------------------------------------------------------------------------
	//  Name : frame_begin (virtual )
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	virtual void frame_begin() {}

	//-----------------------------------------------------------------------------
	//  Name : frame_update (virtual )
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	virtual void frame_update(std::chrono::duration<float> dt) {}

	//-----------------------------------------------------------------------------
	//  Name : frame_render (virtual )
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	virtual void frame_render(std::chrono::duration<float> dt) {}

	//-----------------------------------------------------------------------------
	//  Name : frame_end (virtual )
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	virtual void frame_end();
	
	//-----------------------------------------------------------------------------
	//  Name : set_main ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	inline void set_main(bool isMain) { _is_main = isMain; }

	//-----------------------------------------------------------------------------
	//  Name : is_main ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	inline bool is_main() const { return _is_main; }
protected:

	//-----------------------------------------------------------------------------
	//  Name : onResize (virtual )
	/// <summary>
	/// This function is called so that derived classes can
	/// perform custom actions when the size of the window changes.
	/// </summary>
	//-----------------------------------------------------------------------------
	virtual void onResize();

	//-----------------------------------------------------------------------------
	//  Name : onClose (virtual )
	/// <summary>
	/// This function is called so that derived classes can
	/// perform custom actions when the window is closed
	/// </summary>
	//-----------------------------------------------------------------------------
	virtual void onClose();

	/// Render surface for this window.
	std::shared_ptr<FrameBuffer> _surface;
	///
	bool _is_main = false;
};