using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CircleRotation : MonoBehaviour
{
    Vector3 myPos;
    private float angle;
    public float radius = 5f;
    public float speed = 1f;
    // Start is called before the first frame update
    void Start()
    {
        myPos = GetComponent<Transform>().position;
    }

    // Update is called once per frame
    void Update()
    {
        GetComponent<Transform>().position = new Vector3(myPos.x +radius*Mathf.Cos(angle), myPos.y + radius * Mathf.Sin(angle));
        
        angle += speed * Time.deltaTime;
    }
}
