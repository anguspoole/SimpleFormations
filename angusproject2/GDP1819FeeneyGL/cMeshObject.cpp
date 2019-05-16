#include "cMeshObject.h"

cMeshObject::cMeshObject() 
{
	this->position = glm::vec3(0.0f);
	this->nonUniformScale = glm::vec3(1.0f);

//	this->preRotation = glm::vec3(0.0f);
//	this->postRotation = glm::vec3(0.0f);
	this->setMeshOrientationEulerAngles( glm::vec3(0.0f,0.0f,0.0f));

//	this->m_meshQOrientation = glm::quat( glm::vec3(0.0f,0.0f,0.0f));

	// 
	this->bIsVisible = true;
	this->bIsWireFrame = false;

	// Set unique ID
	this->m_uniqueID = cMeshObject::m_NextID;
	// Increment
	cMeshObject::m_NextID++;	// 32 bit - 4 billion

//	this->objColour = glm::vec3(1.0f, 1.0f, 1.0f);	// white by default

	this->materialDiffuse = glm::vec4(1.0f,1.0f,1.0f,1.0f);	
	this->materialSpecular = glm::vec4(1.0f,1.0f,1.0f,1.0f);

	this->bUseVertexColour = false;

	this->bDontLight = false;

	this->velocity = glm::vec3(0.0f);
	this->accel = glm::vec3(0.0f);
	this->bIsUpdatedByPhysics = false;	// physics ignores by default

	float movetimer = 50.0f;
//	this->radius = 0.0f;

	this->pDebugRenderer = NULL;

	// Set shape to NULL
	this->pTheShape = NULL;
	this->shapeType = cMeshObject::UNKOWN_SHAPE;

	this->aiType = aiBehaviour::NONE;
	this->targetPos = glm::vec3(0.0f);

	return;
}

cMeshObject::cMeshObject(cMeshObject* obj)
{
	this->position = obj->position;
	this->nonUniformScale = obj->nonUniformScale;
	this->setMeshOrientationEulerAngles(glm::vec3(0.0f, 0.0f, 0.0f));
	this->bIsVisible = true;
	this->bIsWireFrame = false;

	// Set unique ID
	this->m_uniqueID = cMeshObject::m_NextID;
	// Increment
	cMeshObject::m_NextID++;	// 32 bit - 4 billion

//	this->objColour = glm::vec3(1.0f, 1.0f, 1.0f);	// white by default
	this->materialDiffuse = obj->materialDiffuse;
	this->materialSpecular = obj->materialSpecular;
	this->bUseVertexColour = false;
	this->bDontLight = false;
	this->velocity = obj->velocity;
	this->accel = obj->accel;
	this->bIsUpdatedByPhysics = obj->bIsUpdatedByPhysics;	// physics ignores by default

	float movetimer = obj->movetimer;

	this->pDebugRenderer = obj->pDebugRenderer;

	// Set shape to NULL
	this->pTheShape = obj->pTheShape;
	this->shapeType = obj->shapeType;

	this->aiType = obj->aiType;
	this->targetPos = obj->targetPos;
}

int cMeshObject::getID(void)
{
	return this->m_uniqueID;
}

void cMeshObject::setDiffuseColour(glm::vec3 newDiffuse)
{
	this->materialDiffuse = glm::vec4( newDiffuse, this->materialDiffuse.a );
	return;
}

void cMeshObject::setAlphaTransparency(float newAlpha)
{
	// RGB A
	this->materialDiffuse.a = newAlpha;	
	return;
}

void cMeshObject::setSpecularColour(glm::vec3 colourRGB)
{
	this->materialSpecular = glm::vec4( colourRGB, this->materialSpecular.a );
	return;
}

void cMeshObject::setSpecularPower(float specPower)
{
	this->materialSpecular.a = specPower;
	return;
}


void cMeshObject::setUniformScale(float scale)
{
	this->nonUniformScale = glm::vec3(scale,scale,scale);
	return;
}
	
//static unsigned int m_NextID; //= 0;

//static 
unsigned int cMeshObject::m_NextID = cMeshObject::STARTING_ID_VALUE;


void cMeshObject::Update(double deltaTime)
{
	if ( this->bIsUpdatedByPhysics )
	{
		// Figure out a line showing the velocity
		glm::vec3 vVel = this->velocity + this->position;
		glm::vec3 vAcc = this->accel + this->position;

		if ( this->pDebugRenderer )		// != NULL
		{
//			this->pDebugRenderer->addLine( this->position, vVel, 
//										   glm::vec3( 0.0f, 1.0f, 0.0f ), 0.0f );
//
//			this->pDebugRenderer->addLine( this->position, vAcc, 
//										   glm::vec3( 0.0f, 1.0f, 1.0f ), 0.0f );
		}//if ( this->pDebugRenderer )	
	}//if ( this->bIsUpdatedByPhysics )

	return;
}
