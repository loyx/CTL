CrowdTask VideoDoc {

    Constraints: 
        Precedence: 
            TakeVideo -> ExtractSummary -> VideoDoc 
        Date: 
            FromNowTo(2023/3/30)
        
    ]

    comupte main():Void = {
        CrowdSO.save("./data", ExtractSummary.returnData)
    }

}

CrowdTask TakeVideo {
    Constraints: 
        Spatial: 
            (108.80, 34.33) - (109.05, 34.20)

    Hparticipant: 
        Location
        LocalTime
        HumanIntelligence
        Video
    
    comupte main(): Video = Hpart.Video
}

CrowdTask ExtractSummary {
    Hparticipant: 
        HumanIntelligence

    comupte main(): = {
        result = CrowdOS.createTask(
            "summary the video", 
            TakeVideo.returnData
            )
        result
    }
}
