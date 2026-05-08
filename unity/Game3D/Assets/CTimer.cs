using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
public class CTimer : MonoBehaviour
{
    public float mTime;
    public int taskD, taskTD;
    public TMP_Text mTimer;
    [SerializeField] TextMeshProUGUI obj;
    public bool isGameOver;
    // Start is called before the first frame update
    void Start()
    {
        mTime = 0;
        isGameOver = false;
        mTimer = GetComponent<TextMeshProUGUI>();
    }
    // Update is called once per frame
    void Update()
    {
        if (isGameOver == false)
        {
            mTime += Time.deltaTime;
            float minutes = Mathf.FloorToInt(mTime / 60);
            float seconds = Mathf.FloorToInt(mTime % 60);
            mTimer.text = string.Format("{0:00}:{1:00} | {2}/{3}", minutes, seconds, taskD, taskTD);
        }else
        {
            mTimer.text = string.Format("Game Over " + "\nTime: " + mTime.ToString("F2"));
        }
    }
}