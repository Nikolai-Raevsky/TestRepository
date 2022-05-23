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
        if (Input.GetKey("right"))
        {
            //transform.position = new Vector3(transform.position.x + moveSpeed * Time.deltaTime, transform.position.y, transform.position.z);
            myRB.velocity = new Vector2(moveSpeed, myRB.velocity.y);
            Debug.Log("right");
            
        }

        //if (Input.GetKeyUp(KeyCode.RightArrow))
        //{
        //    myRB.velocity = new Vector2(0, 0);
        //    Debug.Log("The release of all keys is triggered and the velocity is (0,0)");
        //}

        else if (Input.GetKey("left"))
        {
            //transform.position = new Vector3(transform.position.x - moveSpeed * Time.deltaTime, transform.position.y, transform.position.z);
            myRB.velocity = new Vector2(-moveSpeed, myRB.velocity.y);
            Debug.Log("left");
            
        }

        //if (Input.GetKeyUp(KeyCode.LeftArrow))
        //{
        //    myRB.velocity = new Vector2(0, 0);
        //    Debug.Log("The release of all keys is triggered and the velocity is (0,0)");
        //}
        else
        {
            myRB.velocity = new Vector2(0, myRB.velocity.y);
        }
        if (Input.GetKey("space"))
        {
            //transform.position = new Vector3(transform.position.x, transform.position.y + moveSpeed * Time.deltaTime, transform.position.z);
            myRB.velocity = new Vector2(myRB.velocity.x, jumpModifier);
            //Tomorrow make independent jump height variable
            Debug.Log("Space");
            
        }
        
        //Stopping the momentum has utmost priority
        
    }
   private bool isGrounded()
    {
        float extraHeightText = 1f;
        RaycastHit2D raycastHit = Physics2D.BoxCast(); //Rewatch https://www.youtube.com/watch?v=c3iEl5AwUF8 later
    }    
}
