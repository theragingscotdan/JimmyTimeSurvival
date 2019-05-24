#include "Enemy.h"

Enemy::Enemy()
	:MovingObject()
	//, m_player(nullptr)
	, m_dead(false)
	, m_playerseen(false)
	, m_secondsPassed(0.0f)
	, m_duration(5.0f)
	, m_modifier(0.0f, 0.0f)
{

}

void Enemy::Update(sf::Time _frameTime)
{

}

void Enemy::Collide(GameObject& _collider)
{
	Player* castPlayer = dynamic_cast <Player*>(&_collider);
}

void Enemy::SetActive(bool _active)
{
	m_active = _active;
}

void Enemy::Vision(sf::Vector2f)
{
	//  https://www.gamedev.net/forums/topic/623320-efficient-line-of-sight-algorithm/

}

/*double Enemy::LinearInterpolate(double x0, double x1, double y0, double y1, double x)
{
	return y0 + (x - x0) * (y1 - y0) / (x1 - x0);
}
*/
sf::Vector2f Enemy::QuadEaseOut(float time, float duration, sf::Vector2f startingPoint, sf::Vector2f endPoint)
{
	float t = time / duration;

	float p = -1.0f * t * t + 2.0f * t;

	// determine the total distance to be travelled
	sf::Vector2f totalDistance = endPoint - startingPoint;

	// determine the distance travelled (aka how far we have actually gone so far)
	// by scaling the total distance by our generated scaling factor (p)
	sf::Vector2f distanceTraveled = totalDistance * p;

	// determine the new position by adding the distance travelled to the start point
	sf::Vector2f newPositon = startingPoint + distanceTraveled;

	return newPositon;
}
