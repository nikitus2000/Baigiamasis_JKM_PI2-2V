#include "pch.h"
#include "Render.h"

Render::Render(UINT width, UINT height, std::wstring name) :
	IRender(width, height, name)
	//m_frameIndex(0),
	//m_viewport{ 0.0f, 0.0f, static_cast<float>(width), static_cast<float>(height) },
	//m_scissorRect{0, 0, static_cast<LONG>(width), static_cast<LONG>(height)},
	//m_rtvDescriptorSize(0)
{
}
