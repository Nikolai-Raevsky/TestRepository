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
    public float jumpModifier = .5f;
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
        ////Horizontal movement  OR FIGURE OUT HOW TO MAKE PARABOLA JUMP ARC
        if (Input.GetKey(KeyCode.RightArrow))
        {
            //transform.position = new Vector3(transform.position.x + moveSpeed * Time.deltaTime, transform.position.y, transform.position.z);
            myRB.velocity = new Vector2(moveSpeed*Time.deltaTime, myRB.velocity.y);
            
        }

        if (Input.GetKey(KeyCode.LeftArrow))
        {
            //transform.position = new Vector3(transform.position.x - moveSpeed * Time.deltaTime, transform.position.y, transform.position.z);
            myRB.velocity = new Vector2(-moveSpeed* Time.deltaTime, myRB.velocity.y);
            
        }

        if (Input.GetKey(KeyCode.Space))
        {
            //transform.position = new Vector3(transform.position.x, transform.position.y + moveSpeed * Time.deltaTime, transform.position.z);
            myRB.velocity = new Vector2(myRB.velocity.x, jumpModifier * Time.deltaTime);
            //Tomorrow make independent jump height variable
            Debug.Log("Space");
        }

        if (Input.GetKey(KeyCode.None))
        {
            myRB.velocity = new Vector2(0, 0);
        }
    }
}
