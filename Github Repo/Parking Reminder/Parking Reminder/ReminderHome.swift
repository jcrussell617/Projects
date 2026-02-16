//
//  ContentView.swift
//  Parking Reminder
//
//  Created by Jacob Russell on 2/12/26.
//

import SwiftUI
import MapKit
import CoreLocation

struct ReminderHome: View {
    @StateObject private var locationManager = LocationManager()
    @State private var region: MapCameraPosition = .region(MKCoordinateRegion(
        center: CLLocationCoordinate2D(latitude: 37.7749, longitude: -122.4194),
        span: MKCoordinateSpan(latitudeDelta: 0.01, longitudeDelta: 0.01)))
    @State private var savedSpot: CLLocationCoordinate2D?
    
    var body: some View {
        
        
        VStack {
            
            HStack {
                Image(systemName: "car.fill")
                    .imageScale(.large)
                    .foregroundStyle(Color(.blue))
                    .font(.title)
                Text("Parking Spot Reminder")
                    .font(.title)
                    .fontWeight(.bold)
            }
            .padding(.vertical, 20)
            
            Map(position: $region) {
                // Drop a pin when user saves their spot
                if let savedSpot {
                    Marker("Parked Car", coordinate: savedSpot)
                }
            }
            
            // Follows the user's position on the map
            .onChange(of: locationManager.userLocation) {oldValue, newLocation in
                if let loc = newLocation {
                    region = .region(MKCoordinateRegion(
                        center: loc.coordinate,
                        span: MKCoordinateSpan(latitudeDelta: 0.01, longitudeDelta: 0.01)))
                }
            }
                .padding()
                .cornerRadius(70)
            
            Button(action: {
                // Mark their current spot as parked car
                if let currentLocation = locationManager.userLocation {
                    savedSpot = currentLocation.coordinate
                    
                    region = .region(MKCoordinateRegion(
                        center: currentLocation.coordinate,
                        span: MKCoordinateSpan(latitudeDelta: 0.01, longitudeDelta: 0.01)))
                }
            }) {
                Text(savedSpot == nil ? "Save Parking Spot" : "Change Parking Spot")
                    .padding()
                    .font(.title)
                    .fontWeight(.bold)
                    .foregroundColor(.white)
                    .background(savedSpot == nil ? Color.blue : Color.red)
                    .cornerRadius(20)
            }
        }
    }

}

#Preview {
    ReminderHome()
}
