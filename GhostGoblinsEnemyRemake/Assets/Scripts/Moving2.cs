//THIS IS A TEST USING A UNITY SCRIPT ON THE UNITY MANUAL!!!! DO NOT USE OUTSIDE OF TESTING CONTEXTS


using UnityEngine;

public class Moving2 : MonoBehaviour
{
    //movement speed in units per second
    public float movementSpeed = 5f;

    void Update()
    {
        //get the Input from Horizontal axis
        float horizontalInput = Input.GetAxis("Horizontal");
        //get the Input from Vertical axis
        float verticalInput = Input.GetAxis("Vertical");

        //update the position
        transform.position = transform.position + new Vector3(horizontalInput * movementSpeed * Time.deltaTime, verticalInput * movementSpeed * Time.deltaTime, 0);

        //output to log the position change
        Debug.Log(transform.position);
    }
}