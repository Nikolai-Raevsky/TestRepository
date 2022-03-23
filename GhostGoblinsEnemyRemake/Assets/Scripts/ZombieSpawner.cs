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
    
    // Start is called before the first frame update
    void Start()
    {
        spawnTimerCopy = inbetweenSpawnTimer;
        waveTimerCopy = zombieWaveTimer;
    }

    // Update is called once per frame
    void Update()
    {
        inbetweenSpawnTimer -= Time.deltaTime;
        if (inbetweenSpawnTimer <= 0)
        {
            if(currentZombieNum < maxZombieNum)
            {
                Instantiate(objectToBeSpawned, Vector3.zero, Quaternion.identity);
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
