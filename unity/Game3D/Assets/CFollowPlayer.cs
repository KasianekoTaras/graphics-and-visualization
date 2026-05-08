using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class CFollowPlayer : MonoBehaviour
{
    public GameObject player;
    public float offset = 10;
    // Start is called before the first frame update
    void Start()
    {
        transform.eulerAngles = new Vector3(80, 0, 0);
    }
    // Update is called once per frame
    void Update()
    {
        transform.eulerAngles = new Vector3(80, player.transform.eulerAngles[1], 0);
        transform.position = player.transform.position + new Vector3(0, offset, 0);
    }
}