using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class CPlayerController : MonoBehaviour
{
    Rigidbody rb;
    public float force = 1.0f;
    public float forceTurn = 2.5f;
    private bool isLoadStation = false;
    public GameObject tankPrefab;
    // Start is called before the first frame update
    void Start()
    {
        rb = GetComponent<Rigidbody>();
    }
    // Update is called once per frame
    void Update()
    {
        // Reads the [WSAD] input to control the player movement.
        if (Input.GetKey(KeyCode.W))
        {
            rb.AddForce(transform.forward * force);
        }
        if (Input.GetKey(KeyCode.S))
        {
            rb.AddForce(-transform.forward * force);
        }
        if (Input.GetKey(KeyCode.D))
        {
            rb.AddTorque(transform.up * forceTurn);
        }
        if (Input.GetKey(KeyCode.A))
        {
            rb.AddTorque(-transform.up * forceTurn);
        }
        if (Input.GetKeyDown(KeyCode.Space))
        {
            if (isLoadStation == true)
            {
                // set this object position associated with the PlayerController
                Vector3 pos = transform.position + new Vector3(0f, 2.0f, 0);
                // set rotation
                Quaternion rot = Quaternion.Euler(90.0f, 0, 0);
                // create object using tankPrefab
                Instantiate(tankPrefab, pos, rot);
            }
        }
    }
    void OnTriggerEnter(Collider obj)
    {
        Debug.Log(obj.tag);
        if (obj.tag == "tagLoadStation")
        {
            isLoadStation = true;
            // changes color of the collided object material
        
    obj.GetComponent<Renderer>().material.color = new Color(1.0f, 0, 0, 1);
        }
    }
    void OnTriggerExit(Collider obj)
    {
        if (obj.tag == "tagLoadStation")
        {
            isLoadStation = false;
            obj.GetComponent<Renderer>().material.color = new Color(0, 1.0f, 0, 1);
        }
    }
}