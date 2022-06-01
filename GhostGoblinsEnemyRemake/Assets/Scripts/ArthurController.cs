//-------------------------
//Name: Nikolai Raevsky (nikolai.raevsky@digipen.edu)
//Date: 3/30/2021
//Description: PlayerControls
//Credits: 
//-------------------------


using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ArthurController : MonoBehaviour
{
    public float moveSpeed = .5f;
    public float jumpModifier = .5f;
    Rigidbody2D myRB;
    private BoxCollider2D myCollider;
    [SerializeField] private LayerMask groundLayerMask;
    [SerializeField] private float extraHeightOffset = 0.01f;

    // Start is called before the first frame update
    void Start()
    {
        myRB = GetComponent<Rigidbody2D>();
        myCollider = GetComponent<BoxCollider2D>();
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
        //Movement controls source: https://www.youtube.com/watch?v=44djqUTg2Sg
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
        if (isGrounded() && Input.GetKey("space"))
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
        
        RaycastHit2D raycastHit = Physics2D.BoxCast(myCollider.bounds.center, myCollider.bounds.size - new Vector3(.1f, 0, 0), 0f, Vector2.down, extraHeightOffset, groundLayerMask); //Source: https://www.youtube.com/watch?v=c3iEl5AwUF8 later
        Color rayColor;
        if (raycastHit.collider != null)
        {
            rayColor = Color.green;
        }
        
        else 
        { 
            rayColor = Color.red; 
        }
        Debug.DrawRay(myCollider.bounds.center + new Vector3(myCollider.bounds.extents.x, 0), Vector2.down * (myCollider.bounds.extents.y + extraHeightOffset), rayColor);
        Debug.DrawRay(myCollider.bounds.center - new Vector3(myCollider.bounds.extents.x, 0), Vector2.down * (myCollider.bounds.extents.y + extraHeightOffset), rayColor);
        Debug.DrawRay(myCollider.bounds.center - new Vector3(myCollider.bounds.extents.x, myCollider.bounds.extents.y), Vector2.right * (2 * myCollider.bounds.extents.x + extraHeightOffset), rayColor);
        
        Debug.Log(raycastHit.collider);
        return raycastHit.collider != null;
    
    }    
}
