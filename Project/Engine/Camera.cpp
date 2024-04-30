#include "pch.h"
#include "Camera.h"

Camera::Camera()
{
    m_position = { 0.f, 0.f, 0.f };
    m_rotation = { 0.f, 0.f, 0.f };
}

Camera::~Camera()
{
}

void Camera::SetPosition(Vector3 position)
{
    m_position = position;
}

void Camera::SetRotation(Vector3 rotation)
{
    m_rotation = rotation;
}

Vector3 Camera::GetPosition()
{
    return m_position;
}

Vector3 Camera::GetRotation()
{
    return m_rotation;
}

void Camera::Render()
{
	XMFLOAT3 up, position, lookAt;
	XMVECTOR upVector, positionVector, lookAtVector;
	float yaw, pitch, roll;
	XMMATRIX rotationMatrix;

	up.x =				0.0f;
	up.y =				1.0f;
	up.z =				0.0f;

	upVector =			XMLoadFloat3(&up);

	position.x =		m_position.X;
	position.y =		m_position.Y;
	position.z =		m_position.Z;

	positionVector =	XMLoadFloat3(&position);

	lookAt.x =			0.0f;
	lookAt.y =			0.0f;
	lookAt.z =			1.0f;

	lookAtVector =		XMLoadFloat3(&lookAt);

	pitch =				math::ToRadians(m_rotation.X);
	yaw =				math::ToRadians(m_rotation.Y);
	roll =				math::ToRadians(m_rotation.Z);

	rotationMatrix =	 XMMatrixRotationRollPitchYaw(pitch, yaw, roll);

	lookAtVector =		XMVector3TransformCoord(lookAtVector, rotationMatrix);
	upVector =			XMVector3TransformCoord(upVector, rotationMatrix);

	lookAtVector =		XMVectorAdd(positionVector, lookAtVector);

	m_viewMatrix =		XMMatrixLookAtLH(positionVector, lookAtVector, upVector);
}

void Camera::GetViewMatrix(XMMATRIX& viewMatrix)
{
    viewMatrix = m_viewMatrix;
}
