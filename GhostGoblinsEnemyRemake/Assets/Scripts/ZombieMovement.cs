//-------------------------
//Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
//Date: 3/22/2021
//Description: Program the zombie movement behavior in here. This might also be used to determine the enemy's movement direction but depending on how much 
//I have to do it might be easier to make a separate script for that that also interacts with the enemy transform so I can repurpose it for other enemies
//-------------------------


using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ZombieMovement : MonoBehaviour
{
    public float speed = 5f;
    public float interpolater = .4f;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 target = new Vector3(5, transform.position.y, transform.position.z);
        Vector3 current = transform.position;
        //Update the zombie's position in here
        transform.position = Vector3.MoveTowards(current, Vector3.Lerp(current, target, interpolater), speed * Time.deltaTime);
    }
}
