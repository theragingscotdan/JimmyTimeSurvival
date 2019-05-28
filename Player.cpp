#include "Player.h"
#include "Wall.h"
#include "Spikes.h"
#include "Fire.h"
#include "Rusher.h"
#include "Shooter.h"
#include "ExitLvl2.h"
#include "ExitLvl3.h"
#include "Door.h"
#include "Framework/AssetManager.h"

#define SPEED 250.0f

Player::Player()
	: MovingObject()
	, m_level(nullptr)
	, m_health(100)
	, m_stand(false)
	, m_attack(false)
	, m_justAttacked(false)
	, m_tookDamage(false)
	, m_timeSinceDamage(0.0f)
	, m_canAttack(true)
	, hasToolbox(false)
	, m_oldPosition(0.0f, 0.0f)
	, m_currentHP(100)
	, m_keys(0)
	, m_attackSound()
	, m_destroyed()
	, m_open()
	
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/JimmySprites/JimmyStand2.png"));
	m_attackSound.setBuffer(AssetManager::GetSoundBuffer("audio/PlayerAttack.wav"));
	m_destroyed.setBuffer(AssetManager::GetSoundBuffer("audio/EnemyDestroyed.wav"));
	m_open.setBuffer(AssetManager::GetSoundBuffer("audio/DoorOpen.wav"));
	
}

void Player::Update(sf::Time _frameTime)
{
	// first, assume no keys are pressed
	m_velocity.x = 0.0f;
	m_velocity.y = 0.0f;

	// use the keyboard function to check which keys are currently held down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_velocity.y = -SPEED;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_velocity.x = -SPEED;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_velocity.y = SPEED;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_velocity.x = SPEED;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		AttemptAttack();
		m_justAttacked = true;
		
	}
	else
	{
 		m_attack = false;
		m_sprite.setTexture(AssetManager::GetTexture("graphics/JimmySprites/JimmyStand2.png"));

	}

	
	if (m_tookDamage == true)
	{
		m_timeSinceDamage += _frameTime.asSeconds();

		if (m_timeSinceDamage <= 3.0f)
		{
			m_canAttack = false;
			m_sprite.setTexture(AssetManager::GetTexture("graphics/JimmySprites/JimmyHurt.png"));
			
		}
		else
		{
			m_canAttack = true;
			m_sprite.setTexture(AssetManager::GetTexture("graphics/JimmySprites/JimmyStand2.png"));
			m_tookDamage = false;
			m_timeSinceDamage = 0.0f;
			
			
		}
	}

	// call the update function manually on the parent class
	// This will actually move the character

	MovingObject::Update(_frameTime);
	
	// process animations
	//m_animationSystem.Update(_frameTime);

}

void Player::Collide(GameObject& _collider)
{
	// only do something if the object is a wall
	Wall* wallCollider = dynamic_cast<Wall*>(&_collider);
	Spikes* spikeCollider = dynamic_cast<Spikes*>(&_collider);
	Fire* fireCollider = dynamic_cast<Fire*>(&_collider);
	Rusher* rusherCollider = dynamic_cast<Rusher*>(&_collider);
	Shooter* shooterCollider = dynamic_cast<Shooter*>(&_collider);
	ExitLvl2* blockedCollider = dynamic_cast<ExitLvl2*>(&_collider);
	ExitLvl3* deniedCollider = dynamic_cast<ExitLvl3*>(&_collider);
	Door* doorCollider = dynamic_cast<Door*>(&_collider);


	// if it was a wall we hit, we need to move ourselves
	//outside the wall's bounds, aka back where we were
	if (wallCollider != nullptr)
	{
		// we did hit a wall!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

		// Party time!

		// return to your previous position that we just
		// moved away from this frame
		m_sprite.setPosition(m_previousPosition);
	}
	else if (spikeCollider != nullptr)
	{
		LoseHealth(101);  // reduce the player's hp to 0 which kills them

	}
	else if (fireCollider != nullptr)
	{
		fireCollider->GetCanDamage(); // get the variable from Fire allowing the player to take damage
		//m_stand = true;
		m_tookDamage = true;

		if (fireCollider->GetCanDamage() == true)// && m_stand == true) // if the player can be damaged
		{
			LoseHealth(5); // take damage
			fireCollider->SetCanDamage(false); // then reset the ability to take damage
			//m_stand = false;
		}

	}

	// TODO: Make these enemy collisions more efficient. 
	// Possibly using a list within enemy and having an add to list somewhere in each enemy
	// then include enemy.h and bring the list via pointer/reference
	else if (rusherCollider != nullptr)
	{
		if (rusherCollider->IsActive() == true)
		{
			if (m_attack == true)
			{
				rusherCollider->SetActive(false);
				m_destroyed.play();
			}
			else
			{
				m_sprite.move((m_velocity * -0.125f));
				//m_health -= 40;
				LoseHealth(40);

				m_tookDamage = true;

			}
		}

	}
	else if (shooterCollider != nullptr)
	{
		if (shooterCollider->IsActive() == true)
		{
			if (m_attack == true)
			{
				shooterCollider->SetActive(false);
				m_destroyed.play();
			}
			else
			{
				m_sprite.move(m_velocity * -0.125f);
				// set velocity to -1 instead
				//m_health -= 35;
				LoseHealth(35);
				m_tookDamage = true;
			}
		}
	}
	else if (blockedCollider != nullptr)
	{
		//if (blockedCollider)
		if (!hasToolbox)// || !hasKey)
		{
			m_sprite.setPosition(m_previousPosition);
		}
		else
		{
			blockedCollider->SetActive(false);
		}

	}

	else if (deniedCollider != nullptr)
	{
		//if (blockedCollider)
		if (m_keys < 2)// || !hasKey)
		{
			m_sprite.setPosition(m_previousPosition);
		}
		else

		{
			m_open.play();
			deniedCollider->SetActive(false);
		}

	}

	else if (doorCollider != nullptr)
	{
		//if (blockedCollider)
		if (m_keys < 1)// || !hasKey)
		{
			m_sprite.setPosition(m_previousPosition);
		}
		else

		{
			doorCollider->SetActive(false);
			m_open.play();
		}



		/*if (m_lives <= 0)
		{

		} */
	}
}
void Player::AddHealth(int _changeBy)
{
	m_health += _changeBy;
}

void Player::LoseHealth(int _changeBy)
{
	m_health -= _changeBy;

	if (m_health <= 0)
	{
		Kill();

	}
}

void Player::setLevel(Level* _newLevel)
{
	m_level = _newLevel;
}

int Player::GetHealth()
{
	return m_health;
}

void Player::SetHealth(int _health)
{
	m_health = _health;
}

bool Player::GetAttack()
{
	return m_attack;
}

void Player::SetTookDamage(bool _damaged)
{
	m_tookDamage = _damaged;
}

void Player::SetCanAttack(bool _attack)
{
	m_canAttack = _attack;
}

void Player::Kill()
{
	// reload current level
	if (m_level != nullptr)
		m_level->ReloadLevel();
	
}

void Player::Attack(sf::Event _gameEvent)
{
	if (m_health >= 0)
	{
		if (m_attack == true)
		{

		}
	} 
}

void Player::AttemptAttack()
{
	/*if (m_justAttacked)
	{
		m_canAttack = false;
	}
	*/
	//if (m_tookDamage && (sf::Keyboard::IsHeld(sf::Keyboard::Space))
	if (m_canAttack)
	{
		m_attack = true;
		m_sprite.setTexture(AssetManager::GetTexture("graphics/JimmySprites/JimmyAttack.png"));
		m_attackSound.play();

	}
	else
	{
		m_attack = false;
		//m_sprite.setTexture(AssetManager::GetTexture("graphics/JimmySprites/JimmyStand2.png"));
	}

}

void Player::AdvanceLevel()
{
	if (m_level != nullptr)
	{
		
		m_level->LoadNextLevel();
	}
} 

void Player::SetToolkit(bool _hasTool)
{
	hasToolbox = _hasTool;
}

bool Player::GetToolkit()
{
	return hasToolbox;
}

int Player::GetKeys()
{
	return m_keys;
}

void Player::SetKeys(int _keys)
{
	m_keys += _keys;
}

