#pragma once
//-----------------------------------------------------------------------------
// CameraComponent Header Includes
//-----------------------------------------------------------------------------
#include "../ecs.h"
#include "core/math/math_includes.h"
#include "core/common/basetypes.hpp"
#include "../../rendering/render_pass.h"
#include "../../rendering/camera.h"
//-----------------------------------------------------------------------------
// Forward Declarations
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// Main Class Declarations
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Name : CameraComponent (Class)
/// <summary>
/// Class that contains our core Camera data, used for rendering and other things.
/// </summary>
//-----------------------------------------------------------------------------
class CameraComponent : public runtime::Component
{
	COMPONENT(CameraComponent)
	SERIALIZABLE(CameraComponent)
	REFLECTABLE(CameraComponent, runtime::Component)
public:
	//-------------------------------------------------------------------------
	// Constructors & Destructors
	//-------------------------------------------------------------------------
	CameraComponent();
	CameraComponent(const CameraComponent& camera);
	virtual ~CameraComponent();

	//-------------------------------------------------------------------------
	// Public Methods
	//-------------------------------------------------------------------------
	//-----------------------------------------------------------------------------
	//  Name : set_fov ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	CameraComponent& set_fov(float fovDegrees);

	//-----------------------------------------------------------------------------
	//  Name : set_near_clip ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	CameraComponent& set_near_clip(float distance);

	//-----------------------------------------------------------------------------
	//  Name : set_far_clip ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	CameraComponent& set_far_clip(float distance);

	//-----------------------------------------------------------------------------
	//  Name : set_projection_mode ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	CameraComponent& set_projection_mode(ProjectionMode mode);

	//-----------------------------------------------------------------------------
	//  Name : get_fov ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	float get_fov() const;

	//-----------------------------------------------------------------------------
	//  Name : get_near_clip ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	float get_near_clip() const;

	//-----------------------------------------------------------------------------
	//  Name : get_far_clip ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	float get_far_clip() const;

	//-----------------------------------------------------------------------------
	//  Name : get_projection_mode ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	ProjectionMode get_projection_mode() const;

	//-----------------------------------------------------------------------------
	//  Name : get_camera ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	inline Camera& get_camera() { return _camera; }

	//-----------------------------------------------------------------------------
	//  Name : get_camera ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	inline const Camera& get_camera() const { return _camera; }

	//-----------------------------------------------------------------------------
	//  Name : update ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	void update(const math::transform_t& t);

	//-----------------------------------------------------------------------------
	//  Name : get_hdr ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	bool get_hdr() const;

	//-----------------------------------------------------------------------------
	//  Name : set_hdr ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	void set_hdr(bool hdr);

	//-----------------------------------------------------------------------------
	//  Name : set_viewport_size ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	void set_viewport_size(const uSize& size);

	//-----------------------------------------------------------------------------
	//  Name : get_viewport_size ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	const uSize& get_viewport_size() const;

	//-----------------------------------------------------------------------------
	//  Name : get_ortho_size ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	float get_ortho_size() const;

	//-----------------------------------------------------------------------------
	//  Name : set_ortho_size ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	void set_ortho_size(float size);

	//-----------------------------------------------------------------------------
	//  Name : get_ppu ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	float get_ppu() const;

	//-----------------------------------------------------------------------------
	//  Name : get_render_view ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	inline RenderView& get_render_view() { return _render_view; }
private:
	//-------------------------------------------------------------------------
	// Private Member Variables.
	//-------------------------------------------------------------------------
	/// The camera object this component represents
	Camera _camera;
	/// The render view for this component
	RenderView _render_view;
	/// Is the camera HDR?
	bool _hdr = true;
};