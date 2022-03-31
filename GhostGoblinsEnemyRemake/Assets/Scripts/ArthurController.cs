//-------------------------
//Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
//Date: 3/30/2021
//Description: PlayerControls
//-------------------------


using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ArthurController : MonoBehaviour
{
    public float moveSpeed = .5f;
    Rigidbody2D myRB;
    // Start is called before the first frame update
    void Start()
    {
        myRB = GetComponent<Rigidbody2D>();   
    }

    // Update is called once per frame
    void Update()
    {
        ////Horizontal movement
        //if (Input.GetKey(KeyCode.RightArrow))
        //{
        //    transform.position = new Vector3(transform.position.x + moveSpeed * Time.deltaTime, transform.position.y, transform.position.z);
        //}

        //if (Input.GetKey(KeyCode.LeftArrow))
        //{
        //    transform.position = new Vector3(transform.position.x - moveSpeed * Time.deltaTime, transform.position.y, transform.position.z);
        //}
    }

    private void FixedUpdate()
    {
        ////Horizontal movement //TOMORROW REMAKE IT W/ PHYSICS TO GET MORE CONTROLLER CUSTOMIZERS!! OR FIGURE OUT HOW TO MAKE PARABOLA JUMP ARC
        if (Input.GetKey("right"))
        {
            //transform.position = new Vector3(transform.position.x + moveSpeed * Time.deltaTime, transform.position.y, transform.position.z);
            myRB.velocity = new Vector2(moveSpeed, myRB.velocity.y);
            Debug.Log("Right");
        }

        if (Input.GetKey("left"))
        {
            //transform.position = new Vector3(transform.position.x - moveSpeed * Time.deltaTime, transform.position.y, transform.position.z);
            myRB.velocity = new Vector2(-moveSpeed, myRB.velocity.y);
            Debug.Log("Left");
        }

        if (Input.GetKey("space"))
        {
            //transform.position = new Vector3(transform.position.x, transform.position.y + moveSpeed * Time.deltaTime, transform.position.z);
            myRB.velocity = new Vector2(0, moveSpeed);
            Debug.Log("Space");
        }

        else
        {
            myRB.velocity = new Vector2(0, 0);
        }
    }
}
