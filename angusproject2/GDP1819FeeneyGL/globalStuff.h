#ifndef _globalStuff_HG_
#define _globalStuff_HG_


// globalStuff.h 

// These two OpenGL things are moved to the 
//	globalOpenGLStuff.h file
#include "globalOpenGLStuff.h"
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/vec3.hpp>

#include <string>

#include "sPlyVertex.h"
#include "sPlyTriangle.h"
#include "cMeshObject.h"
#include "sModelDrawInfo.h"
#include "cVAOMeshManager.h"

#include "cLightMangager.h"

#include "Error/CErrorLog.h"

#include "DebugRenderer/iDebugRenderer.h"

#include "cFlyCamera.h"

#include "cJoystickManager.h"

#include "TextureManager/cBasicTextureManager.h"

// The commands
#include "cCommandGroup.h"
// And the commands
#include "cFollowObjectCommand.h"
#include "cAnimationCurveCommand.h"
#include "cWait.h"

#include "cParticleEmitter.h"

#include "cAABB.h"
#include <time.h>

#include "Flock.h"
// ... and more

extern int mode;

//extern glm::vec3 g_CameraEye;	// = glm::vec3( 0.0, 0.0, +10.0f );
//extern glm::vec3 g_CameraAt;	// = glm::vec3( 0.0, 0.0, 0.0f );
extern cFlyCamera* g_pFlyCamera;

extern cJoystickManager* g_pJoysticks;

//// NOTE: These are JUST FOR NOW!!!
//extern glm::vec3 g_lightPos;	// = glm::vec3( 4.0f, 4.0f, 0.0f );
//extern float g_lightBrightness;	// = 1.0f;

extern cVAOMeshManager* g_pTheVAOMeshManager;

extern cBasicTextureManager* g_pTheTextureManager;

extern std::vector<cParticleEmitter*> gAPEs;

// 
// This is a global pointer to a mesh object. 
// You can get at object like this, or you can 
// search for them using the findObjectBy...() 
// functions.
extern cMeshObject* g_pRogerRabbit;
// 

extern cAABBHierarchy* g_pTheTerrain;

// Signature for the ply loader function
bool LoadPlyFileData( std::string fileName );

void LoadModelTypes( cVAOMeshManager* pTheVAOMeshManager, GLuint shaderProgramID );
void LoadModelsIntoScene(cVAOMeshManager* pTheVAOMeshManager, std::vector<cMeshObject*> &vec_pObjectsToDraw);

cMeshObject* findObjectByFriendlyName(std::string theNameToFind);
cMeshObject* findObjectByUniqueID( unsigned int IDToFind );

void DrawObject( cMeshObject* pCurrentMesh,
				 glm::mat4x4 &matModel, 
				 GLuint shaderProgramID );


// *****************************************************************
// This is part of the physics stuff
// (really should be moved to the physics area, not here)
struct sClosestPointData
{
	glm::vec3 thePoint;
	unsigned int triangleIndex;
};
void CalculateClosestPointsOnMesh( sModelDrawInfo theMeshDrawInfo, 
								   glm::vec3 pointToTest, 
								   std::vector<sClosestPointData> &vecPoints );
// *****************************************************************


//https://stackoverflow.com/questions/9878965/rand-between-0-and-1
template <class T>
T getRandBetween0and1(void)
{
	return (T) ((double) rand() / (RAND_MAX)) ;
}

// Inspired by: https://stackoverflow.com/questions/686353/c-random-float-number-generation
template <class T>
T getRandInRange( T min, T max )
{
	double value = 
		min + static_cast <double> (rand()) 
		/ ( static_cast <double> (RAND_MAX/(static_cast<double>(max-min) )));
	return static_cast<T>(value);
}

extern iDebugRenderer* g_pDebugRenderer;

// If true, then the "ambient brightness" spheres will be drawn
extern bool g_bDrawDebugLightSpheres;	// = true


// For physics checkpoint #4
// This is global because I need to update this with the keyboard
extern float g_ProjectileInitialVelocity;

static const glm::vec3 g_ACCEL_GRAVITY = glm::vec3( 0.0f, -5.0f, 0.0f );

#include "cLuaBrain.h"
extern cMeshObject* g_pObjectToRotate;
extern cLuaBrain* p_LuaScripts;

extern std::vector< cMeshObject* > vec_pObjectsToDraw;

extern std::vector< cMeshObject* > aiObjects;

extern std::vector<Flock*> flockList;

extern int windowHeight;
extern int windowWidth;

void ProcessAI(float deltaTime);
void DeleteObjects();

void CreateFlockTest();
Flock* GenerateFlock();

void CreateFormation(int formationType);
void MoveToTarget(float dt);

extern int previousFormation;

extern Flock* smallFlock;
extern bool flockEnabled;

extern std::vector<std::pair<glm::vec3, float>> path;
extern float pathTimer;
extern bool pathForward;
extern bool travelPath;
extern int currentSegment;

void MakePath();
void TravelPath(float dt);
void UpdateFlocks(float dt);

#endif	// _globalStuff_HG_
