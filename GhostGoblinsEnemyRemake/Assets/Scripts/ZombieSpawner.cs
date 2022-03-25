//-------------------------
//Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
//Date: 3/23/2021
//Description: Zombie Spawn Behavior Controller. Takes a GameObject pre-fab and a float to instantiate an object within a specific time frame
//-------------------------
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ZombieSpawner : MonoBehaviour
{
    public GameObject objectToBeSpawned;
    public float inbetweenSpawnTimer = .2f;
    public int maxZombieNum = 3;

    public float zombieWaveTimer = .5f;
    private float waveTimerCopy;
    private int currentZombieNum = 0;
    private float spawnTimerCopy;
    private float screenHalfNumber; //This one will pick which half of the screen the zombies will spawn in
    //These are going to be subrange boundaries for the left and right side of the screen
    public float leftSideMin = -20;
    public float leftSideMax = -10;
    public float rightSideMin = 10;
    public float rightSideMax = 20;
    float spawnX;
    
    
    Vector3 spawnPoint;

    // Start is called before the first frame update
    void Start()
    {
        spawnTimerCopy = inbetweenSpawnTimer;
        waveTimerCopy = zombieWaveTimer;
        
        
    }

    // Update is called once per frame
    void Update()
    {
        //This determines which half of the screen the zombies spawn in.
        screenHalfNumber = Random.Range(1, 3);
        if (screenHalfNumber == 1)
        {
            spawnX = Random.Range(leftSideMin, leftSideMax);
        }

        else
        {
            spawnX = Random.Range(rightSideMin, rightSideMax);
        }

        spawnPoint = new Vector3(spawnX + transform.position.x, transform.position.y, transform.position.z);
        inbetweenSpawnTimer -= Time.deltaTime;
        if (inbetweenSpawnTimer <= 0)
        {
            if(currentZombieNum < maxZombieNum)
            {
                //For instantiater remember to store it in a variable that can be destroyed and to randomize the positions based on the position of an object such as a player)
                Instantiate(objectToBeSpawned, spawnPoint, Quaternion.identity);
                currentZombieNum += 1;
            }

            else
            {
                //I should remember Time.deltaTime as an important component of a lot of timers
                zombieWaveTimer -= Time.deltaTime;
            }

            if (zombieWaveTimer <= 0)
            {
                zombieWaveTimer = waveTimerCopy;
                currentZombieNum = 0; //This is going change once I get the despawner working
            }


            
            inbetweenSpawnTimer = spawnTimerCopy;
        }
        
    }
}
